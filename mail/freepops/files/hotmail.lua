-- ************************************************************************** --
--  FreePOPs @hotmail.com webmail interface
--  
--  Released under the GNU/GPL license
--  Written by Russell Schwager <russell822@yahoo.com>
--  Patched by cdmackie (2007-09-11). 
--    Fixed: lite login, live delete, corrupt messages, stuck at 1st message, classic delete more than 1 message
-- ************************************************************************** --

-- Globals
--
PLUGIN_VERSION = "0.1.84"
PLUGIN_NAME = "hotmail.com"
PLUGIN_REQUIRE_VERSION = "0.2.0"
PLUGIN_LICENSE = "GNU/GPL"
PLUGIN_URL = "http://www.freepops.org/download.php?module=hotmail.lua"
PLUGIN_HOMEPAGE = "http://www.freepops.org/"
PLUGIN_AUTHORS_NAMES = {"Russell Schwager", "D. Milne", "Peter Collingbourne" }
PLUGIN_AUTHORS_CONTACTS = {"russell822 (at) yahoo (.) com", "drmilne (at) safe-mail (.) net", "pcc03 (at) doc (.) ic (.) ac (.) uk>"}
PLUGIN_DOMAINS = { "@hotmail.com","@msn.com","@webtv.com",
      "@charter.com", "@compaq.net","@passport.com", 
      "@hotmail.de", "@hotmail.it", "@hotmail.co.uk", 
      "@hotmail.co.jp", "@hotmail.fr", "@messengeruser.com",
      "@hotmail.com.ar", "@hotmail.co.th", "@hotmail.com.tr"  
      }
PLUGIN_PARAMETERS = {
	{name="folder", description={
		it=[[La cartella che vuoi ispezionare. Quella di default &egrave; Inbox.]],
		en=[[The folder you want to interact with. Default is Inbox.]]}
	},
	{name = "emptyjunk", description = {
		en = [[
Parameter is used to force the plugin to empty the junk folder when it is done
pulling messages.  Set the value to 1.]]
		}	
	},
	{name = "emptytrash", description = {
		it = [[ Viene usato per forzare il plugin a svuotare il cestino quando ha finito di scaricare i messaggi. Se il valore &egrave; 1 questo comportamento viene attivato.]],
		en = [[
Parameter is used to force the plugin to empty the trash when it is done
pulling messages.  Set the value to 1.]]
		}	
	},
	{name = "markunread", description = {
		it = [[ Viene usato per far s&igrave; che il plugin segni come non letti i messaggi che scarica. Se il valore &egrave; 1 questo comportamento viene attivato.]],
		en = [[ Parameter is used to have the plugin mark all messages that it
pulls as unread.  If the value is 1, the behavior is turned on.]]
		}
	},
	{name = "maxmsgs", description = {
		en = [[
Parameter is used to force the plugin to only download a maximum number of messages. ]]
		}	
	},
	{name = "domain", description = {
		en = [[
Parameter is used to override the domain in the email address.  This is used so that users don't
need to add a mapping to config.lua for a hosted hotmail account. ]]
		}	
	},
}
PLUGIN_DESCRIPTIONS = {
	it=[[
Questo plugin vi permette di scaricare la posta da mailbox con dominio della famiglia di @hotmail.com. 
Per usare questo plugin dovrete usare il vostro indirizzo email completo come 
nome utente e la vostra vera password come password.]],
	en=[[
This plugin lets you download mail from @hotmail.com and similar mailboxes. 
To use this plugin you have to use your full email address as the username
and your real password as the password.  For support, please post a question to
the forum instead of emailing the author(s).]]
}

-- Domains supported:  hotmail.com, msn.com, webtv.com, charter.com, compaq.net,
--                     passport.com

-- ************************************************************************** --
--  Global Strings
-- ************************************************************************** --

local globals = {
  -- Max password length in the login page
  --
  nMaxPasswordLen = 16,

  -- Server URL
  --
  strLoginUrl = "http://mail.live.com/",

  strDefaultLoginPostUrl = "https://login.live.com/ppsecure/post.srf",

  -- Login strings
  -- TODO: Define the HTTPS version
  --
  strLoginPostData = "login=%s&domain=%s&passwd=%s&sec=&mspp_shared=&PwdPad=%s&PPSX=Pas&LoginOptions=3",
  strLoginPaddingFull = "xxxxxxxxxxxxxxxx",
  strLoginFailed = "Login Failed - Invalid User name and/or password",

  -- Expressions to pull out of returned HTML from Hotmail corresponding to a problem
  --
  strRetLoginBadLogin = "(memberservices)",
  strRetLoginSessionExpired = "(Sign in)",
  strRetLoginSessionExpiredLive = '(HM%.FppError)',
  strRetStatBusy = "(form name=.hotmail.)",
  
  -- Regular expression to extract the mail server
  --
  
  -- Extract the server to post the login data to
  --
  strLoginPostUrlPattern1='action="([^"]+)"',
  strLoginPostUrlPattern2='type=["]?hidden["]? name="([^"]*)".* value="([^"]*)"',
  strLoginPostUrlPattern3='g_DO."%s".="([^"]+)"',
  strLoginPostUrlPattern4='var g_QS="([^"]+)";',
  strLoginPostUrlPattern5='name="PPFT" id="[^"]+" value="([^"]+)"',
  strLoginDoneReloadToHMHome1='URL=([^"]+)"',
  strLoginDoneReloadToHMHome2='%.location%.replace%("([^"]+)"',
  strLoginDoneReloadToHMHome3="location='([^']+)'",
--  strLoginDoneReloadToHMHome3='location=.([^"%']+)',
  strLoginDoneReloadToHMHome4="img src='([^']+)'",
  strLoginDoneReloadToReloadPage='window%.location=\'([^\']+)\'',
 
  -- Pattern to detect if we are using the live or classic version
  --
  strLiveCheckPattern = '(TodayLight%.aspx)',
  strClassicCheckPattern = '(Windows Live Mail was not able to sign into your account at this time)',
  strLiveMainPagePattern = '<frame.-name="main" src="([^"]+)"',
  strLiveLightPagePattern = 'href="(StylesheetTodayLight)',

  -- Get the crumb value that is needed for every command
  --
  strRegExpCrumb = '&a=([^"&]*)[&"]',
  strRegExpCrumbLive = '"sessionidhash" : "([^"]+)"',                    
  strRegExpUser = '"authuser" : "([^"]+)"',

  -- MSN Inbox Folder Id
  --
  strPatMSNInboxId = "HMFO%('(%d+)'%)[^>]+><img src=.http://[^/]+/i.p.folder.inbox.gif",

  -- Image server pattern
  --
  strImgServerPattern = 'img src="(http://[^/]*)/spacer.gif"',
  strImgServerLivePattern = 'img src="(http://[^/]*)/mail/',

  -- Junk and Trash Folder pattern
  -- 
  strPatLiveTrashId = '"sysfldrtrash".-"([^"]+)"',
  strPatLiveJunkId = '"sysfldrjunk".-"([^"]+)"',

  -- Folder id pattern
  --
  strFolderPattern = '<a href="[^"]+curmbox=([^&]+)&[^"]+" >', 
  strFolderLivePattern = '%("([^"]+)","',
  strFolderLiveInboxPattern = 'sysfldrinbox".-"([^"]+)"',
  strFolderLiveLightInboxPattern = 'href="InboxLight%.aspx%?(FolderID=[^&]+[^"]+)"[^>]+><img src=".-i_inbox.gif"',
  strFolderLiveLightFolderIdPattern = 'FolderID=([^&]+)&[.]*',
  strFolderLiveLightNPattern = '&n=([^&]+)[.]*',
  
  strFolderLiveLightTrashPattern = 'i_trash%.gif" border="0" alt=""/></td>.-<td class="dManageFoldersFolderNameCol"><a href="InboxLight%.aspx%?FolderID=([^&]+)&',
  strFolderLiveLightJunkPattern = 'i_junkfolder%.gif" border="0" alt=""/></td>.-<td class="dManageFoldersFolderNameCol"><a href="InboxLight%.aspx%?FolderID=([^&]+)&',
  strFolderLiveLightPattern = 'href="InboxLight%.aspx%?FolderID=([^&]+)&n=[^"]+" title="',  
  strFolderLiveLightManageFoldersPattern = 'href="ManageFoldersLight%.aspx%?n=([^"]+)"',

  -- Pattern to determine if we have no messages
  --
  strMsgListNoMsgPat = "(<td colspan=10>)", --"(There are no messages in this folder)",

  -- Pattern to determine the total number of messages
  --
  strMsgListCntPattern = "<td width=100. align=center>([^<]+)</td><td align=right nowrap>",
  strMsgListCntPattern2 = "([%d]+) [MmNnBbVv][eai]",
  strMsgListLiveLightCntPattern = '<div class="dItemListHeaderMsgInfo">.- (%d+)</div>',

  -- Used by Stat to pull out the message ID and the size
  --
  strMsgLineLitPattern = ".*<tr>.*<td>[.*]{img}.*</td>.*<td>.*<img>.*</td>.*<td>[.*]{img}.*</td>.*<td>.*<input>.*</td>.*<td>.*</td>.*<td>.*<a>.*</a>.*</td>.*<td>.*</td>.*<td>.*</td>.*<td>.*</td>.*</tr>",
  strMsgLineAbsPattern = "O<O>O<O>[O]{O}O<O>O<O>O<O>O<O>O<O>[O]{O}O<O>O<O>O<X>O<O>O<O>O<O>O<O>O<O>O<O>O<O>O<O>O<O>O<O>O<O>O<O>X<O>O<O>",


  -- Pattern used by Stat to get the next page in the list of messages
  --
  strMsgListNextPagePattern = '(nextpg%.gif" border=0></a>)',
  strMsgListNextPagePatLiveLight = '<a href="([^"]+)"[^>]*><img src="[^_]*_nextpage.gif"',

  -- Pattern used to detect a bad STAT page.
  --
  strMsgListGoodBody = 'i%.p%.attach%.gif',

  -- Pattern used in the Live interface to get the message info
  --
  strMsgLivePatternOld = ',"([^"]+)","[^"]+","[^"]+",[^,]+,[^,]+,[^,]+,[^,]+,"([^"]+)"',
  strMsgLivePattern1 = 'class=.-SizeCell.->([^<]+)</div>',
  strMsgLivePattern2 = 'new HM%.__[^%(]+%("([^"]+)",[tf][^,"]+,"[^"]+",[^,]+,[^,]+',
  strMsgLiveLightPattern = 'ReadMessageId=([^&]+)&[^>]+>.-</a></td>.-<td [^>]+>.-</td>.-<td [^>]+>([^<]+)</td>',

  -- The amount of time that the session should time out at.
  -- This is expressed in seconds
  --
  nSessionTimeout = 28800,  -- 8 hours!

  -- Defined Mailbox names - These define the names to use in the URL for the mailboxes
  --
  strNewFolderPattern = "(curmbox=0)",
  strFolderPrefix = "00000000-0000-0000-0000-000",
  strInbox = "F000000001",

  -- Command URLS
  --
  strCmdBaseLive = "http://%s/mail/",
  strCmdBrowserIgnoreLive = "http://%s/mail/mail.aspx?skipbrowsercheck=true",
  strCmdMsgList = "http://%s/cgi-bin/HoTMaiL?a=%s&curmbox=%s",
  strCmdMsgListNextPage = "&page=%d&wo=",
  strCmdMsgListLiveLight = "http://%s/mail/InboxLight.aspx?FolderID=%s",
  strCmdMsgListLive = "http://%s/mail/mail.fpp?cnmn=Microsoft.Msn.Hotmail.MailBox.GetFolderData&ptid=0&a=%s&au=%s", 
  strCmdMsgListPostLiveOld = "cn=Microsoft.Msn.Hotmail.MailBox&mn=GetFolderData&d=%s,Date,%s,false,0,%s,0,,&MailToken=",
  strCmdMsgListPostLive = 'cn=Microsoft.Msn.Hotmail.MailBox&mn=GetFolderData&d=%s,Date,%s,false,0,%s,0,"","",true,false&v=1&mt=%s',

  strCmdDelete = "http://%s/cgi-bin/HoTMaiL",
  strCmdDeletePost = "curmbox=%s&_HMaction=delete&wo=&SMMF=0", -- &<MSGID>=on
  strCmdDeleteLive = "http://%s/mail/mail.fpp?cnmn=Microsoft.Msn.Hotmail.MailBox.MoveMessages&ptid=0&a=%s&au=%s", 
  strCmdDeletePostLiveOld = 'cn=Microsoft.Msn.Hotmail.MailBox&mn=MoveMessages&d="%s","%s",[%s],[{"%%5C%%7C%%5C%%7C%%5C%%7C0%%5C%%7C%%5C%%7C%%5C%%7C00000000-0000-0000-0000-000000000001%%5C%%7C632901424233870000",{2,"00000000-0000-0000-0000-000000000000",0}}],null,null,0,false,Date&v=1',
  -- strCmdDeletePostLive = 'cn=Microsoft.Msn.Hotmail.MailBox&mn=MoveMessages&d="%s","%s",[%s],[{"%%5C%%7C%%5C%%7C%%5C%%7C0%%5C%%7C%%5C%%7C%%5C%%7C%%5C%%7C00000000-0000-0000-0000-000000000001%%5C%%7C632750213035330000",null}],null,null,0,false,Date,false,true&v=1&mt=%s',
  strCmdDeletePostLive = 'cn=Microsoft.Msn.Hotmail.MailBox&mn=MoveMessages&d="%s","%s",[%s],[{"0%%5C%%7C0%%5C%%7C8C9BDFF65883200%%5C%%7C00000000-0000-0000-0000-000000000001",null}],null,null,0,false,Date,false,true&v=1&mt=%s',
  strCmdDeleteLiveLight = "http://%s/mail/InboxLight.aspx?FolderID=%s&",
  strCmdDeletePostLiveLight = "__VIEWSTATE=&mt=%s&MoveMessageSelector=%s&ToolbarActionItem=MoveMessageSelector&", -- SelectedMessages=%s",
  strCmdMsgView = "http://%s/cgi-bin/getmsg?msg=%s&imgsafe=y&curmbox=%s&a=%s",
  strCmdMsgViewRaw = "&raw=0",
  strCmdMsgViewLive = "http://%s/mail/GetMessageSource.aspx?msgid=%s&gs=true",
  strCmdEmptyTrash = "http://%s/cgi-bin/dofolders?_HMaction=DoEmpty&curmbox=F000000004&a=%s&i=F000000004",
  strCmdLogout = "http://%s/cgi-bin/logout",
  strCmdLogoutLive = "http://%s/mail/logout.aspx",
  strCmdFolders = "http://%s/cgi-bin/folders?&curmbox=F000000001&a=%s",
  strCmdFoldersLiveLight = "http://%s/mail/ManageFoldersLight.aspx?n=%s",
  strCmdMsgUnreadLive = "http://%s/mail/mail.fpp?cnmn=Microsoft.Msn.Hotmail.MailBox.MarkMessages&ptid=0&a=", 
  strCmdMsgUnreadLivePost = "cn=Microsoft.Msn.Hotmail.MailBox&mn=MarkMessages&d=false,[%s]",
  strCmdEmptyTrashLive = "http://%s/mail/mail.fpp?cnmn=Microsoft.Msn.Hotmail.MailBox.EmptyFolder&ptid=0&a=&au=%s", 
  strCmdEmptyTrashLivePost = "cn=Microsoft.Msn.Hotmail.MailBox&mn=EmptyFolder&d=%s,0",
  strCmdEmptyTrashLiveLight = "http://%s/mail/InboxLight.aspx?EmptyFolder=True&FolderID=%s&", 
  strCmdEmptyTrashLiveLightPost = "__VIEWSTATE=&mt=%s&query=&MoveMessageSelector=&ToolbarActionItem=&InfoPaneActionItem=EmptyFolderConfirmYes",
  strCmdMsgReadLive = "http://%s/mail/mail.fpp?cnmn=Microsoft.Msn.Hotmail.MailBox.MarkMessages&ptid=0&a=&au=%s", 
  strCmdMsgReadLivePost = "cn=Microsoft.Msn.Hotmail.MailBox&mn=MarkMessages&d=true,[%s]&v=1&mt=%s",
  strCmdMsgReadLiveLight = "http://%s/mail/ReadMessageLight.aspx?AllowUnsafe=True&Aux=&FolderID=%s&InboxSortAscending=False&InboxSortBy=Date&ReadMessageId=%s",
}

-- ************************************************************************** --
--  State - Declare the internal state of the plugin.  It will be serialized and remembered.
-- ************************************************************************** --

internalState = {
  bStatDone = false,
  bLoginDone = false,
  strUser = nil,
  strPassword = nil,
  browser = nil,
  strMailServer = nil,
  strImgServer = nil,
  strDomain = nil,
  strCrumb = "",
  strMBox = nil,
  strMBoxName = nil,
  bEmptyTrash = false,
  bEmptyJunk = false,
  loginTime = nil,
  bMarkMsgAsUnread = false,
  bLiveGUI = false,
  bLiveLightGUI = false,
  strTrashId = nil,
  strJunkId = nil,
  statLimit = nil,
  strUserId = "",
  strMT = "",
}

-- ************************************************************************** --
--  Debugging functions
-- ************************************************************************** --

-- Set to true to enable Raw Logging
--
local ENABLE_LOGRAW = false

-- The platform dependent End Of Line string
-- e.g. this should be changed to "\n" under UNIX, etc.
local EOL = "\r\n"

-- The raw logging function
--
log = log or {} -- fast hack to make the xml generator happy
log.raw = function ( line, data )
  if not ENABLE_LOGRAW then
    return
  end

  local out = assert(io.open("log_raw.txt", "ab"))
  out:write( EOL .. os.date("%c") .. " : " )
  out:write( line )
  if data ~= nil then
    out:write( EOL .. "--------------------------------------------------" .. EOL )
    out:write( data )
    out:write( EOL .. "--------------------------------------------------" )
  end
  assert(out:close())
end


-- ************************************************************************** --
--  Helper functions
-- ************************************************************************** --

-- Serialize the state
--
-- serial. serialize is not enough powerfull to correcly serialize the 
-- internal state. the problem is the field b. b is an object. this means
-- that is a table (and no problem for this) that has some field that are
-- pointers to functions. this is the problem. there is no easy way for the 
-- serial module to know how to serialize this. so we call b:serialize 
-- method by hand hacking a bit on names
--
function serialize_state()
  internalState.bStatDone = false;
	
  return serial.serialize("internalState", internalState) ..
		internalState.browser:serialize("internalState.browser")
end

-- Computes the hash of our state.  Concate the user, domain, mailbox and password
--
function hash()
  return (internalState.strUser or "") .. "~" ..
         (internalState.strDomain or "") .. "~"  ..
         (internalState.strMBoxName or "") .. "~"  ..
         (internalState.statLimit or "") .. "~"  ..
	 internalState.strPassword -- this asserts strPassword ~= nil
end

function getPage(browser, url)
  local try = 0
  while (try < 3) do
    local body, err = browser:get_uri(url)

    if (body == nil) then
      log.raw("Tried to load: " .. url .. " and got error: " .. err)
    elseif (string.find(body, "We are experiencing higher than normal volume") == nil and 
        string.find(body, "<[Hh][Tt][Mm][Ll]") ~= nil and
        string.find(body, "MSN Hotmail %- ERROR") == nil) then
      return body, err
    end
    try = try + 1
    local newurl = string.match(body, 'Object moved to <a href="([^"]+)"')
    if (newurl ~= nil) then
      return getPage(browser, newurl)
    end
    if (body ~= nil) then
      log.raw("Attempt to load: " .. url .. " failed in attempt: " .. try)
    end
  end

  return nil, nil
end

-- Issue the command to login to Hotmail
--
function loginHotmail()
  log.raw("Entering login")

  -- Check to see if we've already logged in
  --
  if internalState.loginDone then
    return POPSERVER_ERR_OK
  end

  -- Create a browser to do the dirty work
  --
  internalState.browser = browser.new("Mozilla/4.0 (compatible; MSIE 7.0; Windows NT 5.1; YPC 3.0.1; .NET CLR 1.1.4322; .NET CLR 2.0.50727")

  -- Define some local variables
  --
  local username = internalState.strUser
  local password = internalState.strPassword --curl.escape(internalState.strPassword)
  local passwordlen = string.len(internalState.strPassword)
  local domain = internalState.strDomain
  local url = globals.strLoginUrl
  local browser = internalState.browser
  local postdata = nil
  local name, value  
    
  -- DEBUG - Set the browser in verbose mode
  --
--  browser:verbose_mode()

  -- Enable SSL
  --
  browser:ssl_init_stuff()

  -- Retrieve the login page.
  --
  local body, err = getPage(browser, url)

  -- No connection
  --
  if body == nil then
    log.error_print("Login Failed: Unable to make connection")
    log.raw("Login failed: Can't get the page: " .. url .. ", Error: " .. (err or "none"));
    return POPSERVER_ERR_NETWORK
  end

  -- Hotmail will return with the login page.  This page supports a slew of domains.
  -- Pull out the place where we need to post the login information.  Post the form
  -- to login.
  --
  local pattern = string.format(globals.strLoginPostUrlPattern3, domain)
  url = string.match(body, pattern)
  local str = string.match(body, globals.strLoginPostUrlPattern4)
  local str2 = string.match(body, globals.strLoginPostUrlPattern5)
  if (str == nil or str2 == nil) then
    log.error_print(globals.strLoginFailed)
    return POPSERVER_ERR_NETWORK
  end
  if (url == nil) then 
    url = globals.strDefaultLoginPostUrl 
  end
  url = url .. "?" .. str 

  local padding = string.sub(globals.strLoginPaddingFull, 0, globals.nMaxPasswordLen - passwordlen)
  postdata = string.format(globals.strLoginPostData, username, domain, curl.escape(password), padding)
  postdata = postdata .. "&PPFT=" .. str2

  log.dbg("Hotmail - Sending login information to: " .. url)
  body, err = browser:post_uri(url, postdata)
  if (body == nil) then
      log.error_print(globals.strLoginFailed)
      log.raw("Login failed: Sent login info to: " .. (url or "none") .. " and got something we weren't expecting(0):\n" .. err);
      return POPSERVER_ERR_NETWORK
  end

  -- The login page returns a page where a form needs to be submitted.  We'll do it
  -- manually.  Extract the form elements and post the data
  --
  url = string.match(body, globals.strLoginPostUrlPattern1)
  local postdata = nil
  local name, value  
  for name, value in string.gfind(body, globals.strLoginPostUrlPattern2) do
    value = curl.escape(value)
    if postdata ~= nil then
      postdata = postdata .. "&" .. name .. "=" .. value  
    else
      postdata = name .. "=" .. value 
    end
  end
  if (postdata ~= nil) then
    body, err = browser:post_uri(url, postdata)
  end
 
  -- We should be logged in now!  Unfortunately, we aren't done.  Hotmail returns a page
  -- that should auto-reload in a browser but not in curl.  It's the URL for Hotmail Today.
  --
  url = string.match(body, globals.strLoginDoneReloadToHMHome1)
  if url == nil then
    url = string.match(body, globals.strLoginDoneReloadToHMHome2)
    if url == nil then
      log.error_print(globals.strLoginFailed)
      log.raw("Login failed: Sent login info to: " .. (url or "none") .. " and got something we weren't expecting(1):\n" .. body);
      return POPSERVER_ERR_NETWORK
    end
  end

  str = string.match(url, globals.strRetLoginBadLogin)
  if str ~= nil then
    log.error_print(globals.strLoginFailed)
    log.raw("Login failed: Sent login info to: " .. (url or "none") .. " and got something we weren't expecting(2):\n" .. body);
    return POPSERVER_ERR_NETWORK
  end
  body, err = getPage(browser, url)

  -- Shouldn't happen but you never know
  --
  if body == nil then
    log.error_print(globals.strLoginFailed)
    return POPSERVER_ERR_NETWORK
  end

   -- Check to see if we are using a classic account
   --
   local str = string.match(body, globals.strClassicCheckPattern)
   if str ~= nil then
     log.dbg("Hotmail: Detected Classic version.") 
     body, err = browser:get_uri("http://www.hotmail.com")
   end 

  -- Check to see if we are using the new interface and are redirecting.
  --
  str = string.match(body, globals.strLiveCheckPattern)
  local folderBody = body
  if str ~= nil then
    log.dbg("Hotmail: Detected LIVE version.") 
    str = string.format(globals.strCmdBrowserIgnoreLive, browser:wherearewe())
    body, err = browser:get_uri(str)
    str = string.match(body, globals.strLiveMainPagePattern)
    if str ~= nil then
      str = string.format(globals.strCmdBaseLive, browser:wherearewe()) .. str
      body, err = browser:get_uri(str)
    else
      str = string.match(body, globals.strLiveLightPagePattern)
      if (str ~= nil) then
        log.dbg("Hotmail: Detected LIVE version is in LIGHT mode.")
        internalState.bLiveLightGUI = true
      else
        log.error_print(globals.strLoginFailed)
        log.raw("Login failed: Trying to get session id and got something we weren't expecting:\n" .. body);
        return POPSERVER_ERR_NETWORK
      end
    end

    internalState.bLiveGUI = true
  else
    -- One or two more redirects
    --  
    local oldurl = url
    url = string.match(body, globals.strLoginDoneReloadToReloadPage)
    if url ~= nil then
      body, err = browser:get_uri(url)
    end
    url = string.match(body, globals.strLoginDoneReloadToHMHome1)
    if url == nil then
      url = string.match(body, globals.strLoginDoneReloadToHMHome2)
      if url == nil then
        -- Change suggested by 930     
        local authimgurl = string.match(body, globals.strLoginDoneReloadToHMHome4)
          if authimgurl ~= nil then
            browser:get_uri(authimgurl)
          end
        url = string.match(body, globals.strLoginDoneReloadToHMHome3)
        if url == nil then
          log.error_print(globals.strLoginFailed)
          log.raw("Login failed: Sent login info to: " .. (oldurl or "none") .. " and got something we weren't expecting(3):\n" .. body);
          return POPSERVER_ERR_NETWORK
        end  
        -- End change
      end
    end
    body, err = browser:get_uri(url)
  end

  -- Extract the crumb - This is needed for deletion of items
  --
  if (internalState.bLiveLightGUI ~= true) then
    local user = nil
    if (internalState.bLiveGUI == true) then
      str = string.match(body, globals.strRegExpCrumbLive)
      user = string.match(body, globals.strRegExpUser)
    else
      str = string.match(body, globals.strRegExpCrumb)
    end

    if str == nil then
      log.error_print("Can't get the 'a' value. This will lead to problems!")
      internalState.strCrumb = ""
    else
      internalState.strCrumb = str
  
      -- Debug Message
      -- 
      log.dbg("Hotmail Crumb value: " .. str .. "\n")
    end

    if user == nil then
      log.error_print("Can't get the 'authuser' value. This will lead to problems!")
      internalState.strUserId = ""
    else
      internalState.strUserId = user
  
      -- Debug Message
      -- 
      log.dbg("Hotmail Authuser value: " .. user .. "\n")
    end
  end

  -- Get the MT cookie value
  --
  local cookie = browser:get_cookie('mt')
  if (cookie ~= nil) then
    internalState.strMT = cookie.value
    log.dbg("Hotmail mt value: " .. cookie.value)
  end

  -- Save the mail server
  --
  internalState.strMailServer = browser:wherearewe()

  -- DEBUG Message
  --
  log.dbg("Hotmail Server: " .. internalState.strMailServer .. "\n")

  -- Find the image server
  --
  if (internalState.bLiveGUI == true) then
    str = string.match(body, globals.strImgServerLivePattern)
  else
    str = string.match(body, globals.strImgServerPattern)
  end
  
  if str ~= nil then
    internalState.strImgServer = str
    log.dbg("Hotmail image server: " .. str)
  else
    internalState.strImgServer = internalState.strMailServer
    log.dbg("Couldn't figure out the image server.  Using the mail server as a default.")
    log.raw("Login failed: Should be logged in right now but am not.  Last page loaded: " .. url .. " with body:\n" .. body);
  end

  -- Note the time when we logged in
  --
  internalState.loginTime = os.clock();

  -- If we haven't set the folder yet, then it is a custom one and we need to grab it
  --
  internalState.strMBoxName = string.gsub(internalState.strMBoxName, '%-', "%%-")
  if (internalState.strMBox == nil and internalState.bLiveGUI == false) then
    local url = string.format(globals.strCmdFolders, internalState.strMailServer, 
      internalState.strCrumb)
    body, err = browser:get_uri(url)
    str = string.match(body, globals.strFolderPattern .. internalState.strMBoxName .. "</a>")
    if (str == nil and domain == "msn.com" and internalState.strMBoxName == "Inbox") then
      str = string.match(body, globals.strPatMSNInboxId)
    end
    if (str == nil) then
      log.error_print("Unable to figure out folder id with name: " .. internalState.strMBoxName)
      return POPSERVER_ERR_NETWORK
    else
      internalState.strMBox = str
      log.dbg("Hotmail - Using folder (" .. internalState.strMBox .. ")")
    end
  elseif (internalState.bLiveGUI == true and internalState.bLiveLightGUI == false) then 
    -- Get some folder id's
    --
    local inboxId = string.match(body, globals.strFolderLiveInboxPattern)

    -- Get the trash folder id and the junk folder id
    --
    str = string.match(body, globals.strPatLiveTrashId) 
    if str ~= nil then
      internalState.strTrashId = str
      log.dbg("Hotmail - trash folder id: " .. str)
    else
      log.error_print("Unable to detect the folder id for the trash folder.  Deletion may fail.")
    end

    str = string.match(body, globals.strPatLiveJunkId) 
    if str ~= nil then
      internalState.strJunkId = str
      log.dbg("Hotmail - junk folder id: " .. str)
    else
      log.error_print("Unable to detect the folder id for the junk folder.  Deletion may fail.")
    end

    if (internalState.strMBoxName == "Inbox") then
      str = inboxId
    elseif (internalState.strMBoxName == "Junk" or internalState.strMBoxName == "Junk E%-Mail") then
      str = internalState.strJunkId
    else
      str = getFolderId(inboxId)
    end

    if (str == nil) then
      log.error_print("Unable to figure out folder id with name: " .. internalState.strMBoxName)
      return POPSERVER_ERR_NETWORK
    else
      internalState.strMBox = str
      log.dbg("Hotmail - Using folder (" .. internalState.strMBox .. ")")
    end
  elseif (internalState.bLiveGUI == true and internalState.bLiveLightGUI == true) then 
    -- cdmackie: Live Light has an "n" value in the folders list that we need to get
    local n = string.match(body, globals.strFolderLiveLightManageFoldersPattern)
    local url = string.format(globals.strCmdFoldersLiveLight, internalState.strMailServer, n)    
    
    body, err = browser:get_uri(url)
    
    -- cdmackie: we then extract the querystring and apend the InboxId with the N value
    local inboxQueryString = string.match(body, globals.strFolderLiveLightInboxPattern)
    local inboxId = string.match(inboxQueryString, globals.strFolderLiveLightFolderIdPattern)
    local inboxN = string.match(inboxQueryString, globals.strFolderLiveLightNPattern)
    inboxId = inboxId .. "&n=" .. inboxN

    if (internalState.strMBoxName == "Inbox") then
      str = inboxId
    else
      str = string.match(body, globals.strFolderLiveLightPattern .. internalState.strMBoxName)
    end

    if (str == nil) then
      log.error_print("Unable to figure out folder id with name: " .. internalState.strMBoxName)
      return POPSERVER_ERR_NETWORK
    else
      internalState.strMBox = str
      log.dbg("Hotmail - Using folder (" .. internalState.strMBox .. ")")
    end

    -- Get the trash folder id and the junk folder id
    --
    str = string.match(body, globals.strFolderLiveLightTrashPattern) 
    if str ~= nil then
      internalState.strTrashId = str
      log.dbg("Hotmail - trash folder id: " .. str)
    else
      log.error_print("Unable to detect the folder id for the trash folder.  Deletion may fail.")
    end

    str = string.match(body, globals.strFolderLiveLightJunkPattern) 
    if str ~= nil then
      internalState.strJunkId = str
      log.dbg("Hotmail - junk folder id: " .. str)
    else
      log.error_print("Unable to detect the folder id for the junk folder.  Deletion may fail.")
    end
  end

  -- Note that we have logged in successfully
  --
  internalState.bLoginDone = true
    
  -- Debug info
  --
  log.dbg("Created session for " .. 
    internalState.strUser .. "@" .. internalState.strDomain .. "\n")

  -- Return Success
  --
  log.raw("Successful login")
  return POPSERVER_ERR_OK
end

function getFolderId(inboxId) 
  local cmdUrl = string.format(globals.strCmdMsgListLive, internalState.strMailServer,
    internalState.strCrumb, internalState.strUserId)
  local post = string.format(globals.strCmdMsgListPostLive, inboxId, 0, 0, internalState.strMT)
  local body, err = internalState.browser:post_uri(cmdUrl, post)
  local str = string.match(body, globals.strFolderLivePattern .. internalState.strMBoxName .. '","i_')
  return str
end

-- Download a single message
--
function downloadMsg(pstate, msg, nLines, data)
  -- Make sure we aren't jumping the gun
  --
  local retCode = stat(pstate)
  if retCode ~= POPSERVER_ERR_OK then 
    return retCode 
  end
	
  -- Local Variables
  --
  local browser = internalState.browser
  local uidl = get_mailmessage_uidl(pstate, msg)
  
  local url = string.format(globals.strCmdMsgView, internalState.strMailServer,
    uidl, internalState.strMBox, internalState.strCrumb);
  local markReadUrl = url
  url = url .. globals.strCmdMsgViewRaw
  if (internalState.bLiveGUI == true) then
    url = string.format(globals.strCmdMsgViewLive, internalState.strMailServer, uidl)
  end

  -- Debug Message
  --
  log.dbg("Getting message: " .. uidl .. ", URL: " .. url)

  -- Define a structure to pass between the callback calls
  --
  local cbInfo = {
    -- Whether this is the first call of the callback
    --
    bFirstBlock = true,
    nAttempt = 0,
    bRetry = true,

    -- String hacker
    --
    strHack = stringhack.new(),

    -- Lines requested (-2 means not limited)
    --
    nLinesRequested = nLines,

    -- Lines Received - Not really used for anything
    --
    nLinesReceived = 0,

    -- Buffer
    --
    strBuffer = "",

    -- addition
    cb_uidl = uidl,     --  to provide the uidl for later... 
    bEndReached = false  	-- this is a hack, I know...
    -- end of addition
  }
	
  -- Define the callback
  --
  local cb = downloadMsg_cb(cbInfo, data)

  -- Start the download on the body
  -- 
  while (cbInfo.bRetry == true and cbInfo.nAttempt < 3) do
    local f, err = browser:pipe_uri(url, cb)
    if err then
      -- Log the error
      --
      log.raw("Message: " .. cbInfo.cb_uidl .. " received error: " .. err)
    end
  end
  if (cbInfo.bRetry == true) then
    log.error_print("Message: " .. cbInfo.cb_uidl .. " failed to download.")
    log.raw("Message: " .. cbInfo.cb_uidl .. " failed to download.")
    return POPSERVER_ERR_NETWORK
  end

  -- Handle whatever is left in the buffer
  --
  local body = cbInfo.strBuffer
  if (string.len(body) > 0 and cbInfo.nLinesRequested == -2) then
    log.raw("Message: " .. cbInfo.cb_uidl .. ", left over buffer being processed: " .. body)
    body = cleanupBody(body, cbInfo)
    
    -- cdmackie: rather than test for </pre> to determine end, just set it seen
    -- as we've reached end of buffer..and hotmail doesn't always send "</pre>"
    cbInfo.bEndReached = true
    cbInfo.nLinesReceived = -1;
    -- apply same fixup from cleanupbody to remove dead tags
    if (string.len(body) > 6) then
      local idx = string.find(string.sub(body, -6), "([&<])")
      if (idx ~= nil) then
        idx = idx - 1
        cbInfo.strBuffer = string.sub(body, -6 + idx)
        local len = string.len(body) - 6 + idx
        body = string.sub(body, 1, len)
      end
    end
    -- make sure we end in a crlf
    if (string.sub(body, -2, -1) ~= "\r\n") then
      body = body .. "\r\n"
    end
    
    if (cbInfo.bEndReached == false) then
      log.dbg("Forcing a CRLF to end the message as it isn't clear the message is ended properly")
      popserver_callback("\r\n\0", data)
    end
    body = cbInfo.strHack:dothack(body) .. "\0"
    popserver_callback(body, data)
  elseif (cbInfo.bEndReached == false and cbInfo.nLinesRequested == -2) then
      popserver_callback("\r\n\0", data)
  end

  -- Mark the message as read
  --
  if internalState.bMarkMsgAsUnread == false and internalState.bLiveGUI == false then
    log.raw("Message: " .. cbInfo.cb_uidl .. ", Marking message as being done.")
    browser:get_head(markReadUrl)
  elseif internalState.bMarkMsgAsUnread == false and internalState.bLiveGUI and internalState.bLiveLightGUI == false then
    log.raw("Message: " .. cbInfo.cb_uidl .. ", Marking message as read.")
    url = string.format(globals.strCmdMsgReadLive, internalState.strMailServer, internalState.strUserId)
    local post = string.format(globals.strCmdMsgReadLivePost, uidl, internalState.strMT)
    browser:post_uri(url, post)
  elseif internalState.bMarkMsgAsUnread == false and internalState.bLiveGUI and internalState.bLiveLightGUI then
    log.raw("Message: " .. cbInfo.cb_uidl .. ", Marking message as read.")
    url = string.format(globals.strCmdMsgReadLiveLight, internalState.strMailServer, internalState.strMBox, uidl)
    browser:get_head(url)
  elseif internalState.bMarkMsgAsUnread == true and internalState.bLiveGUI == true then
    log.raw("Message: " .. cbInfo.cb_uidl .. ", Marking message as unread.")
    url = string.format(globals.strCmdMsgUnreadLive, internalState.strMailServer)
    local post = string.format(globals.strCmdMsgUnreadLivePost, uidl)
    browser:post_uri(url, post)
  end

  log.raw("Message: " .. cbInfo.cb_uidl .. ", Completed!")
  return POPSERVER_ERR_OK
end

-- Callback for the retr function
--
function downloadMsg_cb(cbInfo, data)
	
  return function(body, len)
    log.raw("In download callback: " .. cbInfo.cb_uidl)    

    -- Is this the first block?  If so, make sure we have a valid message
    --
    if (cbInfo.bFirstBlock == true) then
      if (string.find(body, "<pre>")) then
        cbInfo.bRetry = false
        log.raw("Message: " .. cbInfo.cb_uidl .. " was loaded successfully.")
      else
        cbInfo.bRetry = true   
        cbInfo.nAttempt = cbInfo.nAttempt + 1
        log.raw("Message: " .. cbInfo.cb_uidl .. " failed on attempt: " .. cbInfo.nAttempt .. ", Body: " .. body)
        log.raw("out download callback: " .. cbInfo.cb_uidl)    
        return 0, nil
      end
    end 

    -- Are we done with Top and should just ignore the chunks
    --
    if (cbInfo.nLinesReceived == -1) then
      log.raw("out download callback: " .. cbInfo.cb_uidl .. ", Sent: <Nothing>")    
      return 0, nil
    end

    -- Update the buffer
    --
    body = cbInfo.strBuffer .. body
    cbInfo.strBuffer = ""
    if (string.len(body) > 6) then
      local idx = string.find(string.sub(body, -6), "([&<])")
      if (idx ~= nil) then
        idx = idx - 1
        cbInfo.strBuffer = string.sub(body, -6 + idx)
        local len = string.len(body) - 6 + idx
        body = string.sub(body, 1, len)
      end
    end

    body = cleanupBody(body, cbInfo)

    -- Perform our "TOP" actions
    --
    if (cbInfo.nLinesRequested ~= -2) then
      body = cbInfo.strHack:tophack(body, cbInfo.nLinesRequested)

      -- Check to see if we are done and if so, update things
      --
      if cbInfo.strHack:check_stop(cbInfo.nLinesRequested) then
        cbInfo.nLinesReceived = -1;
        if (string.sub(body, -2, -1) ~= "\r\n") then
          body = body .. "\r\n"
        end
      else
        cbInfo.nLinesReceived = cbInfo.nLinesRequested - 
          cbInfo.strHack:current_lines()
      end
    end

    -- End the strings properly
    --
    body = cbInfo.strHack:dothack(body) .. "\0"

    -- Send the data up the stream
    --
    popserver_callback(body, data)
			
    log.raw("out download callback: " .. cbInfo.cb_uidl .. ", Sent: " .. body)    
    return len, nil
  end
end

function cleanupHeaders(headers, cbInfo)
  -- Cleanup the headers.  They are HTML-escaped.  
  --
  local origHeaders = headers
  local bMissingTo = false    -- it seems hotmail server sometimes disregards To: when 'raw=0' ? 
                              --   probably only in internal HoTMaiL-service letters, where the actual 
                              --   internet message headers do not contain actual To:-field
  local bMissingID = false    -- when no Message-ID -field seems to have been automatically generated ?
  local bodyrest = ""

  headers, bodyrest = string.match(headers, "^(.-)\r*\n%s*\r*\n(.*)$" )

  if (headers == nil) then
    log.dbg("Hotmail: unable to parse out message headers.  Extra headers will not be used.")
    return origHeaders
  end  

  headers = string.gsub(headers, "%s+$", "\n")
  headers = headers .. "\n";
  headers = string.gsub(headers, "\n\n", "\n")
  headers = string.gsub(headers, "\r\n", "\n")
  headers = string.gsub(headers, "\n", "\r\n")

  --
  -- some checking...
  --
  if string.find(headers, "(To:)") == nil then
    bMissingTo = true
  end
  if string.find(headers, "(Message%-I[dD]:)") == nil then
    bMissingID = true
  end

  -- Add some headers
  --
  if bMissingTo ~= false then
    headers = headers .. "To: " .. internalState.strUser .. "@" .. internalState.strDomain .. "\r\n" ;
  end

  if bMissingID ~= false then
    local msgid = cbInfo.cb_uidl .. "@" .. internalState.strMailServer -- well, if we do not have any better choice...
    headers = headers .. "Message-ID: <" .. msgid .. ">\r\n"  
  end

  headers = headers .. "X-FreePOPs-User: " .. internalState.strUser .. "@" .. internalState.strDomain .. "\r\n"
  headers = headers .. "X-FreePOPs-Domain: " .. internalState.strDomain .. "\r\n"
  headers = headers .. "X-FreePOPs-Folder: " .. internalState.strMBox .. "\r\n"
  headers = headers .. "X-FreePOPs-MailServer: " .. internalState.strMailServer .. "\r\n"
  headers = headers .. "X-FreePOPs-ImageServer: " .. internalState.strImgServer .. "\r\n"
  headers = headers .. "X-FreePOPs-MsgNumber: " .. "<" .. cbInfo.cb_uidl .. ">" .. "\r\n"

  -- make the final touch...
  --
  headers = headers .. "\r\n" .. bodyrest

  return headers 
end

function cleanupBody(body, cbInfo)
  -- check to see whether the end of message has already been seen...
  --
  if (cbInfo.bEndReached == true) then
    return ("") ; 	-- in this case we pass nothing past the end of message
  end

  -- Did we reach the end of the message
  --
  -- cdmackie: test for the end after we've processed the buffers instead
  -- GetMessageSource sometimes returns only "</" instead of "</pre>"
  --if (string.find(body, "(</pre>)") ~= nil) then
  --  cbInfo.nLinesReceived = -1;
  --  cbInfo.bEndReached = true 
  --end

  -- The only parts we care about are within <pre>..</pre>
  --
  body = string.gsub(body, "<pre>[%s]*", "")
  body = string.gsub(body, "</pre>.-$", "\n")

  -- Clean up the end of line, and replace HTML tags
  --
  body = string.gsub(body, "&#9;", "\t")
  body = string.gsub(body, "&#09;", "\t")
  body = string.gsub(body, "&#10;", "\n")
  body = string.gsub(body, "&#13;", "\r")
  body = string.gsub(body, "&#32;", " ")
  body = string.gsub(body, "&#33;", "!")
  body = string.gsub(body, "&#35;", "#")
  body = string.gsub(body, "&#36;", "$")
  -- cdmackie: this should be escaped
  body = string.gsub(body, "&#37;", "%%")
  body = string.gsub(body, "&#38;", "&")
  body = string.gsub(body, "&#39;", "'")
  body = string.gsub(body, "&#40;", "(")
  body = string.gsub(body, "&#41;", ")")
  body = string.gsub(body, "&#42;", "*")
  body = string.gsub(body, "&#43;", "+")
  body = string.gsub(body, "&#44;", ",")
  body = string.gsub(body, "&#45;", "-")
  body = string.gsub(body, "&#46;", ".")
  body = string.gsub(body, "&#47;", "/")
  body = string.gsub(body, "&#58;", ":")
  body = string.gsub(body, "&#59;", ";")
  body = string.gsub(body, "&#60;", "<")

  -- cdmackie: these mess up QP and b64 encoded attachments
  --body = string.gsub(body, "&#61;2E", ".")
  --body = string.gsub(body, "&#61;3D", "=")
  --body = string.gsub(body, "&#61;20", " ")
  --body = string.gsub(body, "&#61;09", "\t")
  --body = string.gsub(body, "&#61;96", "-")
  --body = string.gsub(body, "&#61;\r\n", "")
  --body = string.gsub(body, "&#61;92", "'")

  body = string.gsub(body, "&#61;", "=")
  body = string.gsub(body, "&#62;", ">")
  body = string.gsub(body, "&#63;", "?")
  body = string.gsub(body, "&#64;", "@")
  body = string.gsub(body, "&#91;", "[")
  body = string.gsub(body, "&#92;", "\\")
  body = string.gsub(body, "&#93;", "]")
  body = string.gsub(body, "&#94;", "^")
  body = string.gsub(body, "&#95;", "_")
  body = string.gsub(body, "&#96;", "`")
  body = string.gsub(body, "&#123;", "{")
  body = string.gsub(body, "&#124;", "|")
  body = string.gsub(body, "&#125;", "}")
  body = string.gsub(body, "&#126;", "~")

  body = string.gsub(body, "\r", "")
  body = string.gsub(body, "\n", "\r\n")
  -- cdmackie: these mess up QP attachments
  --body = string.gsub(body, "&amp;", "&")
  --body = string.gsub(body, "&lt;", "<")
  --body = string.gsub(body, "&gt;", ">")
  --body = string.gsub(body, "&quot;", "\"")
  body = string.gsub(body, "&#34;", "\"")
  --body = string.gsub(body, "&nbsp;", " ")
  body = string.gsub(body, "<!%-%-%$%$imageserver%-%->", internalState.strImgServer)

  -- cdmackie: POP protocol: lines starting with a dot must be escaped dotdot
  body = string.gsub(body, "\r\n%.", "\r\n%.%.")

  -- We've now at least seen one block, attempt to clean up the headers
  --
  if (cbInfo.bFirstBlock == true) then
    cbInfo.bFirstBlock = false 
    body = cleanupHeaders(body, cbInfo)
  end

  return body
end

-- ************************************************************************** --
--  Pop3 functions that must be defined
-- ************************************************************************** --

-- Extract the user, domain and mailbox from the username
--
function user(pstate, username)
  -- Get the user, domain, and mailbox
  -- TODO:  mailbox - for now, just inbox
  --
  local domain = freepops.get_domain(username)
  local user = freepops.get_name(username)

  internalState.strDomain = domain
  internalState.strUser = user

  -- Override the domain variable if it is set in the login parameter
  --
  local val = (freepops.MODULE_ARGS or {}).domain or nil
  if val ~= nil then
    log.dbg("Hotmail: Using overridden domain: " .. val)
    internalState.strDomain = val
  end

  -- If the flag emptyTrash is set to 1 ,
  -- the trash will be emptied on 'quit'
  --
  local val = (freepops.MODULE_ARGS or {}).emptytrash or 0
  if val == "1" then
    log.dbg("Hotmail: Trash folder will be emptied on exit.")
    internalState.bEmptyTrash = true
  end

  -- If the flag emptyjunk is set to 1 ,
  -- the trash will be emptied on 'quit'
  --
  local val = (freepops.MODULE_ARGS or {}).emptyjunk or 0
  if val == "1" then
    log.dbg("Hotmail: Junk folder will be emptied on exit.")
    internalState.bEmptyJunk = true
  end

  -- If the flag markunread=1 is set, then we will mark all messages
  -- that we pull as unread when done.
  --
  local val = (freepops.MODULE_ARGS or {}).markunread or 0
  if val == "1" then
    log.dbg("Hotmail: All messages pulled will be marked unread.")
    internalState.bMarkMsgAsUnread = true
  end

  -- If the flag maxmsgs is set,
  -- STAT will limit the number of messages to the flag
  --
  val = (freepops.MODULE_ARGS or {}).maxmsgs or 0
  if tonumber(val) > 0 then
    log.dbg("Hotmail: A max of " .. val .. " messages will be downloaded.")
    internalState.statLimit = tonumber(val)
  end

  -- Get the folder
  --
  local mbox = (freepops.MODULE_ARGS or {}).folder
  if mbox == nil then
    internalState.strMBoxName = "Inbox"
    return POPSERVER_ERR_OK
  else
    mbox = curl.unescape(mbox)
    internalState.strMBoxName = mbox
    log.say("Using Custom mailbox set to: " .. internalState.strMBoxName .. ".\n")
  end

  return POPSERVER_ERR_OK
end

-- Perform login functionality
--
function pass(pstate, password)
  -- Store the password
  --
  -- truncate password if longer than nMaxPasswordLen characters to mimic broken web page behavior
  if string.len(password) > globals.nMaxPasswordLen then
    password = string.sub(password, 0, globals.nMaxPasswordLen)
  end
  
  internalState.strPassword = password

  -- Get a session
  --
  local sessID = session.load_lock(hash())

  -- See if we already have a session.  We want to prevent
  -- multiple sessions for a given account
  --
  if sessID ~= nil then
    -- Session exists
    -- This code is copied from example.  It doesn't make sense to me.
    --
  
    -- Check to see if it is locked
    -- Why "\a"?
    --
    if sessID == "\a" then
      log.dbg("Error: Session locked - Account: " .. internalState.strUser .. 
        "@" .. internalState.strDomain .. "\n")
      return POPSERVER_ERR_LOCKED
    end
	
    -- Load the session which looks to be a function pointer
    --
    local func, err = loadstring(sessID)
    if not func then
      log.error_print("Unable to load saved session (Account: " ..
        internalState.strUser .. "@" .. internalState.strDomain .. "): ".. err)
      return loginHotmail()
    end
		
    log.dbg("Session loaded - Account: " .. internalState.strUser .. 
      "@" .. internalState.strDomain .. "\n")

    -- Execute the function saved in the session
    --
    func()
		
    return POPSERVER_ERR_OK
  else
    -- Create a new session by logging in
    --
    return loginHotmail()
  end
end

-- Quit abruptly
--
function quit(pstate)
  session.unlock(hash())
  return POPSERVER_ERR_OK
end

-- Update the mailbox status and quit
--
function quit_update(pstate)
  -- Make sure we aren't jumping the gun
  --
  local retCode = stat(pstate)
  if retCode ~= POPSERVER_ERR_OK then 
    return retCode 
  end

  -- Local Variables
  --
  local browser = internalState.browser
  local cmdUrl = string.format(globals.strCmdDelete, internalState.strMailServer)
  local cnt = get_popstate_nummesg(pstate)
  local dcnt = 0
  local postBase = string.format(globals.strCmdDeletePost, internalState.strMBox)
  local post = postBase
  local uidls = ""
  local uidlsLight = ""

  -- Cycle through the messages and see if we need to delete any of them
  -- 
  for i = 1, cnt do
    if internalState.bLiveGUI == false and get_mailmessage_flag(pstate, i, MAILMESSAGE_DELETE) then
      dcnt = dcnt + 1
      post = post .. "&" .. get_mailmessage_uidl(pstate, i) .. "=on"

      -- Send out in a batch of 5
      --
      if math.mod(dcnt, 5) == 0 then
        log.dbg("Sending Delete URL: " .. cmdUrl .. "Post Data: " .. post .. "\n")
        local body, err = browser:post_uri(cmdUrl, post)
        if not body or err then
          log.error_print("Unable to delete messages.\n")
        end
       
        -- Reset the variables
        --
        dcnt = 0
        post = postBase
      end
    elseif internalState.bLiveGUI == true and internalState.bLiveLightGUI and get_mailmessage_flag(pstate, i, MAILMESSAGE_DELETE) then
      -- cdmackie: uidlsLight should be appended for multiple messages
      uidlsLight = uidlsLight .. "SelectedMessages=" .. get_mailmessage_uidl(pstate, i) .. "&"
      dcnt = dcnt + 1
    elseif internalState.bLiveGUI == true and get_mailmessage_flag(pstate, i, MAILMESSAGE_DELETE) then
      if i > 1 then
        uidls = uidls .. "," .. get_mailmessage_uidl(pstate, i)
      else
        uidls = get_mailmessage_uidl(pstate, i)
      end
      dcnt = dcnt + 1
    end
  end

  -- Send whatever is left over
  --
  if dcnt > 0 and internalState.bLiveGUI == false then
    log.dbg("Sending Delete URL: " .. cmdUrl .. "Post Data: " .. post .. "\n")
    local body, err = browser:post_uri(cmdUrl, post)
    if not body or err then
      log.error_print("Unable to delete messages.\n")
    end
  elseif dcnt > 0 and internalState.bLiveGUI and internalState.bLiveLightGUI == true then
    cmdUrl = string.format(globals.strCmdDeleteLiveLight, internalState.strMailServer, internalState.strMBox)
    post = string.format(globals.strCmdDeletePostLiveLight, internalState.strMT, 
      internalState.strTrashId) .. uidlsLight
    log.dbg("Sending Trash url: " .. cmdUrl .. " - " .. post)
    local body, err = browser:post_uri(cmdUrl, post)
  elseif dcnt > 0 and internalState.bLiveGUI then
    cmdUrl = string.format(globals.strCmdDeleteLive, internalState.strMailServer, internalState.strCrumb, internalState.strUserId)
    uidls = string.gsub(uidls, ",", '","')
    uidls = '"' .. uidls .. '"'
    post = string.format(globals.strCmdDeletePostLive, internalState.strMBox, 
      internalState.strTrashId, uidls, internalState.strMT)
    log.dbg("Sending Trash url: " .. cmdUrl .. " - " .. post)
    local body, err = browser:post_uri(cmdUrl, post)
    if (body == nil) then -- M7 Only - DELETE SOON!
      post = string.format(globals.strCmdDeletePostLiveOld, internalState.strMBox, 
        internalState.strTrashId, uidls)
      local body, err = browser:post_uri(cmdUrl, post)
    end
  end

  -- Empty the trash
  --
  if internalState.bEmptyTrash and internalState.bLiveGUI == false then
    if internalState.strCrumb ~= '' then
      cmdUrl = string.format(globals.strCmdEmptyTrash, internalState.strMailServer,internalState.strCrumb)
      log.dbg("Sending Empty Trash URL: " .. cmdUrl .."\n")
      local body, err = getPage(browser, cmdUrl)
      if not body or err then
        log.error_print("Error when trying to empty the trash with url: ".. cmdUrl .."\n")
      end
    else
      log.error_print("Cannot empty trash - crumb not found\n")
    end
  elseif internalState.bEmptyTrash and internalState.bLiveGUI and internalState.bLiveLightGUI == true then
    cmdUrl = string.format(globals.strCmdEmptyTrashLiveLight, internalState.strMailServer, internalState.strTrashId)
    local post = string.format(globals.strCmdEmptyTrashLiveLightPost, internalState.strMT)
    log.dbg("Sending Empty Trash URL: " .. cmdUrl .."\n")
    local body, err = browser:post_uri(cmdUrl, post)
    if not body or err then
      log.error_print("Error when trying to empty the trash with url: ".. cmdUrl .."\n")
    end
  elseif internalState.bEmptyTrash and internalState.bLiveGUI then
    cmdUrl = string.format(globals.strCmdEmptyTrashLive, internalState.strMailServer, internalState.strUserId)
    local post = string.format(globals.strCmdEmptyTrashLivePost, internalState.strTrashId)
    log.dbg("Sending Empty Trash URL: " .. cmdUrl .."\n")
    local body, err = browser:post_uri(cmdUrl, post)
    if not body or err then
      log.error_print("Error when trying to empty the trash with url: ".. cmdUrl .."\n")
    end
  end

  -- Empty the Junk Folder
  -- 
  if internalState.bEmptyJunk and internalState.bLiveGUI and internalState.bLiveLightGUI == true then
    cmdUrl = string.format(globals.strCmdEmptyTrashLiveLight, internalState.strMailServer, internalState.strJunkId)
    local post = string.format(globals.strCmdEmptyTrashLiveLightPost, internalState.strMT)
    log.dbg("Sending Empty Junk URL: " .. cmdUrl .."\n")
    local body, err = browser:post_uri(cmdUrl, post)
    if not body or err then
      log.error_print("Error when trying to empty the junk folder with url: ".. cmdUrl .."\n")
    end
  elseif internalState.bEmptyJunk and internalState.bLiveGUI then
    cmdUrl = string.format(globals.strCmdEmptyTrashLive, internalState.strMailServer, internalState.strUserId)
    local post = string.format(globals.strCmdEmptyTrashLivePost, internalState.strJunkId)
    log.dbg("Sending Empty Junk URL: " .. cmdUrl .."\n")
    local body, err = browser:post_uri(cmdUrl, post)
    if not body or err then
      log.error_print("Error when trying to empty the junk folder with url: ".. cmdUrl .."\n")
    end
  end

  -- Should we force a logout.  If this session runs for more than a day, things
  -- stop working
  --
  local currTime = os.clock()
  local diff = currTime - internalState.loginTime
  if diff > globals.nSessionTimeout then 
    if (internalState.bLiveGUI) then
      cmdUrl = string.format(globals.strCmdLogoutLive, internalState.strMailServer)
    else
      cmdUrl = string.format(globals.strCmdLogout, internalState.strMailServer)
    end
    log.dbg("Sending Logout URL: " .. cmdUrl .. "\n")
    local body, err = getPage(browser, cmdUrl)
 
    log.dbg("Logout forced to keep hotmail session fresh and tasty!  Yum!\n")
    log.dbg("Session removed - Account: " .. internalState.strUser .. 
      "@" .. internalState.strDomain .. "\n")
    log.raw("Session removed (Forced by Hotmail timer) - Account: " .. internalState.strUser .. 
      "@" .. internalState.strDomain) 
    session.remove(hash())
    return POPSERVER_ERR_OK
  end

  -- Save and then Free up the session
  --
  session.save(hash(), serialize_state(), session.OVERWRITE)
  session.unlock(hash())

  log.dbg("Session saved - Account: " .. internalState.strUser .. 
    "@" .. internalState.strDomain .. "\n")

  return POPSERVER_ERR_OK
end

-- Stat command for the live gui
--
function LiveStat(pstate) 
  -- Local variables
  -- 
  local browser = internalState.browser
  local nMsgs = 0
  local nTotMsgs = 0;
  local nMaxMsgs = 999 
  if internalState.statLimit ~= nil then
    nMaxMsgs = internalState.statLimit
  end  

  local cmdUrl = string.format(globals.strCmdMsgListLive, internalState.strMailServer,
    internalState.strCrumb, internalState.strUserId)
  local post = string.format(globals.strCmdMsgListPostLive, internalState.strMBox, nMaxMsgs, nMaxMsgs, internalState.strMT)

  -- Debug Message
  --
  log.dbg("Stat URL: " .. cmdUrl .. "\n");
		
  -- Initialize our state
  --
  set_popstate_nummesg(pstate, nMsgs)

  -- Iterate over the messages
  --
  local body, err = browser:post_uri(cmdUrl, post)
  if (body == nil) then
    -- Use the M7 way -- REMOVE THIS AT SOME POINT!
    --
    post = string.format(globals.strCmdMsgListPostLiveOld, internalState.strMBox, nMaxMsgs, nMaxMsgs)
    body, err = browser:post_uri(cmdUrl, post)
  end
  log.raw(body)

  -- Let's make sure the session is still valid
  --
  local strSessExpr = string.match(body, globals.strRetLoginSessionExpiredLive)
  if strSessExpr ~= nil then
    -- Invalidate the session
    --
    internalState.bLoginDone = nil
    session.remove(hash())
    log.raw("Session Expired - Last page loaded: " .. cmdUrl .. ", Body: " .. body)

    -- Try Logging back in
    --
    local status = loginHotmail()
    if status ~= POPSERVER_ERR_OK then
      return POPSERVER_ERR_NETWORK
    end
	
    -- Reset the local variables		
    --
    browser = internalState.browser

    -- Retry to load the page
    --
    body, err = browser:post_uri(cmdUrl, post)
  end

  -- Go through the list of messages (M7 - DELETE SOON!)
  --
  for uidl, size in string.gfind(body, globals.strMsgLivePatternOld) do
    nMsgs = nMsgs + 1
    if (nMsgs <= nMaxMsgs) then  
      log.dbg("Processed STAT - Msg: " .. nMsgs .. ", UIDL: " .. uidl .. ", Size: " .. size)
      set_popstate_nummesg(pstate, nMsgs)
      set_mailmessage_size(pstate, nMsgs, size)
      set_mailmessage_uidl(pstate, nMsgs, uidl)
    end
  end

  -- Go through the list of messages (M8)
  --
  local cnt = 0
  local i = 1
  local sizes = {}
  for size in string.gfind(body, globals.strMsgLivePattern1) do
    cnt = cnt + 1
    local kbUnit = string.match(size, "([Kk])")
    size = string.match(size, "([%d%.,]+) [KkMm]")
    if (size ~= nil) then
      size = string.gsub(size, ",", ".")
    end
    if size ~= nil and tonumber(size) ~= nil then
      if not kbUnit then 
        size = math.max(tonumber(size), 0) * 1024 * 1024
      else
        size = math.max(tonumber(size), 0) * 1024
      end
    else
      size = 1024
    end
    sizes[cnt] = size
  end

  for uidl in string.gfind(body, globals.strMsgLivePattern2) do
    nMsgs = nMsgs + 1
    if (nMsgs <= nMaxMsgs) then
      log.dbg("Processed STAT - Msg: " .. nMsgs .. ", UIDL: " .. uidl .. ", Size: " .. sizes[i])

      set_popstate_nummesg(pstate, nMsgs)
      set_mailmessage_size(pstate, nMsgs, sizes[i])
      set_mailmessage_uidl(pstate, nMsgs, uidl)
      i = i + 1
    end
  end

  -- Update our state
  --
  internalState.bStatDone = true

  -- Function completed successfully
  --
  return POPSERVER_ERR_OK
end

-- Stat command - Get the number of messages and their size
--
function stat(pstate)

  -- Have we done this already?  If so, we've saved the results
  --
  if internalState.bStatDone then
    return POPSERVER_ERR_OK
  end

  if internalState.bLiveGUI and internalState.bLiveLightGUI == false then
    return LiveStat(pstate)
  end

  -- Local variables
  -- 
  local browser = internalState.browser
  local nPage = 1
  local nMsgs = 0
  local nTotMsgs = 0
  local lastNMsgs = 0
  local cmdUrl = ""
  if (internalState.bLiveLightGUI) then    
    cmdUrl = string.format(globals.strCmdMsgListLiveLight, internalState.strMailServer, 
      internalState.strMBox);
  else
    cmdUrl = string.format(globals.strCmdMsgList, internalState.strMailServer,
      internalState.strCrumb, internalState.strMBox);
  end
  local baseUrl = cmdUrl
  local nextPageUrl = nil

  -- Keep a list of IDs that we've seen.  With yahoo, their message list can 
  -- show messages that we've already seen.  This, although a bit hacky, will
  -- keep the unique ones.  We'll need to search the table on every message which
  -- really sucks!
  --
  local knownIDs = {}

  -- Debug Message
  --
  log.dbg("Stat URL: " .. cmdUrl .. "\n");
		
  -- Initialize our state
  --
  set_popstate_nummesg(pstate, nMsgs)

  -- Local function to process the list of messages, getting id's and sizes
  --
  local function funcProcess(body)
    lastNMsgs = nMsgs

    -- Find out if there are any messages
    -- 
    local nomesg = string.match(body, globals.strMsgListNoMsgPat)
    if (nomesg ~= nil) then
      return true, nil
    end

    -- Tokenize out the message ID and size for each item in the list
    --    
    local items = mlex.match(body, globals.strMsgLineLitPattern, globals.strMsgLineAbsPattern)
    log.dbg("Stat Count: " .. items:count())

    -- Remember the count
    --
    local cnt = items:count()
    if cnt == 0 then
      return true, nil
    end 
		
    -- Cycle through the items and store the msg id and size
    --
    for i = 1, cnt do
      local uidl = items:get(0, i - 1) 
      local size = items:get(1, i - 1)

      if not uidl or not size then
        log.say("Hotmail Module needs to fix it's individual message list pattern matching.\n")
        return nil, "Unable to parse the size and uidl from the html"
      end

      -- Get the message id..
      --
      uidl = string.match(uidl, 'name="([^"]+)"')

      local bUnique = true
      for j = 0, nMsgs do
        if knownIDs[j + 1] == uidl then
          bUnique = false
          break
        end        
      end

      -- Convert the size from it's string (4KB or 2MB) to bytes
      -- First figure out the unit (KB or just B)
      --
      local kbUnit = string.match(size, "([Kk])")
      size = string.match(size, "([%d%.,]+)[KkMm]")
      if (size ~= nil) then
        size = string.gsub(size, ",", ".")
      end
      if (size ~= nil and tonumber(size) ~= nil) then
        if not kbUnit then 
          size = math.max(tonumber(size), 0) * 1024 * 1024
        else
          size = math.max(tonumber(size), 0) * 1024
        end
      else
        size = 1024
      end

      -- Save the information
      --
      if bUnique == true and ((nMsgs < nTotMsgs and nTotMsgs ~= 0) or nTotMsgs == 0) then
        nMsgs = nMsgs + 1
        log.dbg("Processed STAT - Msg: " .. nMsgs .. ", UIDL: " .. uidl .. ", Size: " .. size)
        set_popstate_nummesg(pstate, nMsgs)
        set_mailmessage_size(pstate, nMsgs, size)
        set_mailmessage_uidl(pstate, nMsgs, uidl)
        knownIDs[nMsgs] = uidl
      end
    end

    -- We are done with this page, increment the counter
    --
    nPage = nPage + 1		
    
    return true, nil
  end 


  -- Local function to process the list of messages, getting id's and sizes
  --
  local function funcProcessLiveLight(body)
    lastNMsgs = nMsgs

    -- Figure out if there are more pages with messages
    --
    nextPageUrl = string.match(body, globals.strMsgListNextPagePatLiveLight)

    -- Tokenize out the message ID and size for each item in the list
    --    
    for uidl, size in string.gfind(body, globals.strMsgLiveLightPattern) do

      if not uidl or not size then
        log.say("Hotmail Module needs to fix it's individual message list pattern matching.\n")
        return nil, "Unable to parse the size and uidl from the html"
      end

      local bUnique = true
      for j = 0, nMsgs do
        if knownIDs[j + 1] == uidl then
          bUnique = false
          break
        end        
      end

      -- Convert the size from it's string (4KB or 2MB) to bytes
      -- First figure out the unit (KB or just B)
      --
      local kbUnit = string.match(size, "([Kk])")
      size = string.match(size, "([%d%.,]+)[KkMm]")
      if (size ~= nil) then
        size = string.gsub(size, ",", ".")
      end
      if (size ~= nil and tonumber(size) ~= nil) then
        if not kbUnit then 
          size = math.max(tonumber(size), 0) * 1024 * 1024
        else
          size = math.max(tonumber(size), 0) * 1024
        end
      else
        size = 1024
      end

      -- Save the information
      --
      if bUnique == true and ((nMsgs < nTotMsgs and nTotMsgs ~= 0) or nTotMsgs == 0) then
        nMsgs = nMsgs + 1
        log.dbg("Processed STAT - Msg: " .. nMsgs .. ", UIDL: " .. uidl .. ", Size: " .. size)
        set_popstate_nummesg(pstate, nMsgs)
        set_mailmessage_size(pstate, nMsgs, size)
        set_mailmessage_uidl(pstate, nMsgs, uidl)
        knownIDs[nMsgs] = uidl
      end
    end

    -- We are done with this page, increment the counter
    --
    nPage = nPage + 1		
    
    return true, nil
  end 

  -- Local Function to check for more pages of messages.  If found, the 
  -- change the command url
  --
  local function funcCheckForMorePages(body) 
    -- 
    if (internalState.bLiveLightGUI) then
      if (nextPageUrl == nil) then
        return true
      else
        cmdUrl = "http://" .. internalState.strMailServer .. "/mail/" .. nextPageUrl
        return false
      end		
    end

    -- See if there are messages remaining
    --
    if nMsgs < nTotMsgs then
      cmdUrl = baseUrl .. string.format(globals.strCmdMsgListNextPage, nPage)
      return false
    else
      -- For western languages, our patterns don't work so use a backup pattern.
      --
      if (lastNMsgs == nMsgs) then
        return true
      end

      if (nTotMsgs == 0 and 
          string.find(body, globals.strMsgListNextPagePattern) ~= nil) then
        cmdUrl = baseUrl .. string.format(globals.strCmdMsgListNextPage, nPage)
        return false
      end
      return true
    end
  end

  -- Local Function to get the list of messages
  --
  local function funcGetPage()  
    -- Debug Message
    --
    log.dbg("Debug - Getting page: ".. cmdUrl)

    -- Get the page and check to see if we got results
    --
    local body, err = getPage(browser, cmdUrl)
    if body == nil then
      return body, err
    end

    -- Check to see if we got a good page back.  The folder list is
    -- notorous for returning Server busy or page not available
    --
    if (internalState.bLiveLightGUI == false and string.find(body, globals.strRetStatBusy) == nil) then
      return nil, "Hotmail is returning an error page."
    end

    -- Is the session expired
    --
    local strSessExpr = string.match(body, globals.strRetLoginSessionExpired)
    if strSessExpr ~= nil then
      -- Invalidate the session
      --
      internalState.bLoginDone = nil
      session.remove(hash())
      log.raw("Session Expired - Last page loaded: " .. cmdUrl .. ", Body: " .. body)

      -- Try Logging back in
      --
      local status = loginHotmail()
      if status ~= POPSERVER_ERR_OK then
        return nil, "Session expired.  Unable to recover"
      end
	
      -- Reset the local variables		
      --
      browser = internalState.browser
      if (internalState.bLiveLightGUI) then    
        cmdUrl = string.format(globals.strCmdMsgListLiveLight, internalState.strMailServer, 
          internalState.strMBox);
      else
        cmdUrl = string.format(globals.strCmdMsgList, internalState.strMailServer,
          internalState.strCrumb, internalState.strMBox);
      end
      baseUrl = cmdUrl
      if nPage > 1 then
        cmdUrl = cmdUrl .. string.format(globals.strCmdMsgListNextPage, nPage)
      end

      -- Retry to load the page
      --
      return getPage(browser, cmdUrl)
    end

    -- Get the total number of messages
    --
    if nTotMsgs == 0 then
      local strTotMsgs
      if (internalState.bLiveLightGUI == false) then    
        strTotMsgs = string.match(body, globals.strMsgListCntPattern)
      else
        strTotMsgs = string.match(body, globals.strMsgListLiveLightCntPattern)
      end
      if strTotMsgs == nil then
        nTotMsgs = 0
      else 
        -- The number of messages can be in one of two patterns
        --
        if (internalState.bLiveLightGUI == false) then    
          nTotMsgs = string.match(strTotMsgs, globals.strMsgListCntPattern2)
          if (nTotMsgs == nil) then
            nTotMsgs = 0
          end
        else 
          nTotMsgs = strTotMsgs
        end
        nTotMsgs = tonumber(nTotMsgs)
      end

      if internalState.statLimit ~= nil then
        local nMaxMsgs = internalState.statLimit
        if (nTotMsgs > nMaxMsgs) then
          nTotMsgs = nMaxMsgs
        end
      end  

      log.dbg("Total messages in message list: " .. nTotMsgs)
    end

    -- Make sure the page is valid
    -- 
    if internalState.bLiveLightGUI == false and string.find(body, globals.strMsgListGoodBody) == nil then
      return nil, "Hotmail returned with an invalid page."
    end
	
    return body, err
  end


  -- Run through the pages and pull out all the message pieces from
  -- all the message lists
  --
  local fnProcess = funcProcess
  if (internalState.bLiveLightGUI) then
    fnProcess = funcProcessLiveLight
  end
  if not support.do_until(funcGetPage, funcCheckForMorePages, fnProcess) then
    log.error_print("STAT Failed.\n")
    session.remove(hash())
    log.raw("Session removed (STAT Failure) - Account: " .. internalState.strUser .. 
      "@" .. internalState.strDomain) 
    return POPSERVER_ERR_NETWORK
  end
	
  -- Update our state
  --
  internalState.bStatDone = true
	
  -- Check to see that we completed successfully.  If not, return a network
  -- error.  This is the safest way to let the email client now that there is
  -- a problem but that it shouldn't drop the list of known uidls.
  if (nMsgs < nTotMsgs) then
    return POPSERVER_ERR_NETWORK
  end

  -- Return that we succeeded
  --
  return POPSERVER_ERR_OK
end

-- Fill msg uidl field
--
function uidl(pstate,msg)
  return common.uidl(pstate, msg)
end

-- Fill all messages uidl field
--
function uidl_all(pstate)
  return common.uidl_all(pstate)
end

-- Fill msg size
--
function list(pstate,msg)
  return common.list(pstate, msg)
end

-- Fill all messages size
--
function list_all(pstate)
  return common.list_all(pstate)
end

-- Unflag each message marked for deletion
--
function rset(pstate)
  return common.rset(pstate)
end

-- Mark msg for deletion
--
function dele(pstate,msg)
  return common.dele(pstate, msg)
end

-- Do nothing
--
function noop(pstate)
  return common.noop(pstate)
end

-- Retrieve the message
--
function retr(pstate, msg, data)
  downloadMsg(pstate, msg, -2, data)
  return POPSERVER_ERR_OK
end

-- Top Command (like retr)
--
function top(pstate, msg, nLines, data)
  downloadMsg(pstate, msg, nLines, data)
  return POPSERVER_ERR_OK
end

-- Plugin Initialization - Pretty standard stuff.  Copied from the manual
--  
function init(pstate)
  -- Let the log know that we have been found
  --
  log.dbg(PLUGIN_NAME .. "(" .. PLUGIN_VERSION ..") found!\n")

  -- Import the freepops name space allowing for us to use the status messages
  --
  freepops.export(pop3server)
	
  -- Load dependencies
  --

  -- Serialization
  --
  require("serial")

  -- Browser
  --
  require("browser")
	
  -- MIME Parser/Generator
  --
  require("mimer")

  -- Common module
  --
  require("common")
	
  -- Run a sanity check
  --
  freepops.set_sanity_checks()

  -- Let the log know that we have initialized ok
  --
  log.dbg(PLUGIN_NAME .. "(" .. PLUGIN_VERSION ..") initialized!\n")


  -- Everything loaded ok
  --
  return POPSERVER_ERR_OK
end

-- EOF
-- ************************************************************************** --
