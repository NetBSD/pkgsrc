#!/bin/ksh
[ x$HOMEPAGE = x ] && HOMEPAGE=http://www.sun.com/staroffice/
[ x$SITE = x ] && SITE=http://jsecom11b.sun.com/
[ x"$COUNTRY" = x"" ] && COUNTRY="United States"
if [ -f /usr/share/calendar/calendar.birthday -a \
	-f /usr/share/dict/words -a \
	-f /usr/share/dict/propernames -a \
	-f /usr/share/misc/zipcodes -a \
	-f /usr/share/misc/na.phone ]; then
	export A=$RANDOM;FIRSTNAME=`tail -$(($A % $(wc -l < /usr/share/dict/propernames))) /usr/share/dict/propernames | head -1 | sed -e 's/ /+/g'`
	export A=$RANDOM;LASTNAME=`tail -$(($A % $(wc -l < /usr/share/dict/propernames))) /usr/share/dict/propernames | head -1 | sed -e 's/ /+/g'`
	export A=$RANDOM;ADDR=`tail -$(($A * 8 % $(wc -l < /usr/share/dict/words))) /usr/share/dict/words | head -1 | sed -e 's/ /+/g'`
	ADDR=`echo $ADDR | awk '{ print toupper(substr($0, 1, 1)) substr($0, 2) }'`
	export A=$RANDOM;ACCT=`tail -$(($A * 8 % $(wc -l < /usr/share/dict/words))) /usr/share/dict/words | head -1 | cut -c 1-8 | sed -e 's/ /+/g'`
	export A=$RANDOM;PASS=`tail -$(($A * 8 % $(wc -l < /usr/share/dict/words))) /usr/share/dict/words | head -1 | cut -c 1-8 | sed -e 's/ /+/g'`
	export A=$RANDOM;HN=`tail -$(($A * 8 % $(wc -l < /usr/share/dict/words))) /usr/share/dict/words | head -1 | sed -e 's/ /+/g'`
	case $(($RANDOM % 4)) in
		0) DIR="N";;
		1) DIR="E";;
		2) DIR="W";;
		3) DIR="S";;
	esac
	case $(($RANDOM % 5)) in
		0) ST="St";;
		1) ST="Rd";;
		2) ST="Blvd";;
		3) ST="Ln";;
		4) ST="Ct";;
	esac
	ADDR=`echo "$RANDOM+$DIR.+$ADDR+$ST."`
	export A=$RANDOM;FOO=`tail -$(($A * 2% $(wc -l < /usr/share/misc/zipcodes))) /usr/share/misc/zipcodes | head -1`
	ZIP=`echo "$FOO" | cut -c 1-5 | sed -e 's/ /+/g'`
	CITY=`echo "$FOO" | sed -e 's/.*:\(.*\),.*/\1/' -e 's/ /+/g'`
	STATE=`echo "$FOO" | sed -e 's/.*, *\(.*\)/\1/' -e 's/ /+/g'`
	AC=`grep $STATE /usr/share/misc/na.phone | head -1 | cut -c 1-3`
	PHONE=`ps -ax | md5 | sed -e 's/[a-f]//'g | sed -e 's/\([2-9]..\)\(....\).*/\1-\2/'`
	PHONE=`echo "($AC)+$PHONE" | sed -e 's/ /+/g'`
	EMAIL="$ACCT@$HN.com"
else
	INTERACTIVE=1
fi

while [ "$INTERACTIVE" = "1" ]; do
	echo ""
	echo "=========================================================================="
	echo "  Please enter the following information for registration and downloading "
	echo "  from \"$HOMEPAGE\".  (Alternatively, you can hit"
	echo "  <Ctrl-C> now, download  StarOffice manually, and restart 'make')        "
	echo "=========================================================================="
	echo ""
	echo -n "First Name [$FIRSTNAME]: "
	read ans && [ "$ans" != "" ] && FIRSTNAME="$ans"
	echo -n "Last Name [$LASTNAME]: "
	read ans && [ "$ans" != "" ] && LASTNAME="$ans"
	echo -n "Street Address [$ADDR]: "
	read ans && [ "$ans" != "" ] && ADDR="$ans"
	echo -n "City [$CITY]: "
	read ans && [ "$ans" != "" ] && CITY="$ans"
	echo -n "State (Code) [$STATE]: "
	read ans && [ "$ans" != "" ] && STATE="$ans"
	echo -n "ZIP [$ZIP]: "
	read ans && [ "$ans" != "" ] && ZIP="$ans"
	echo -n "Phone [$PHONE]: "
	read ans && [ "$ans" != "" ] && PHONE="$ans"
	old="$EMAIL"
	echo -n "EMail [$EMAIL]: "
	read ans && [ "$ans" != "" ] && EMAIL="$ans"
	[ "$old" = "$ACCT@$HN.com" ] && ACCT=`echo $EMAIL | sed -e 's=\([^@]\)@.*=\1='`
	echo -n "Account (Login) to use [$ACCT]: "
	read ans && [ "$ans" != "" ] && ACCT="$ans"
	echo -n "Password (will be visible on your terminal!) [$PASS]: "
	read ans && [ "$ans" != "" ] && PASS="$ans"
	echo ""
	echo -n "Are the data you entered correct [y/N]? "
	read ans && [ "$ans" = "y" -o "$ans" = "Y" ] && INTERACTIVE=0
	echo ""
done

echo ""
echo "=========================================================================="
echo "  Attempting to download from $HOMEPAGE.  This may"
echo "  fail if user information is invalid.  If downloading fails, you can     "
echo "  retry or download StarOffice manually.                                  "
echo "=========================================================================="
echo ""

COUNTRY=`echo $COUNTRY | sed -e 's/ /+/g'`
FIRSTNAME=`echo $FIRSTNAME | sed -e 's/ /+/g'`
LASTNAME=`echo $LASTNAME | sed -e 's/ /+/g'`
ADDR=`echo $ADDR | sed -e 's/ /+/g'`
CITY=`echo $CITY | sed -e 's/ /+/g'`
STATE=`echo $STATE | sed -e 's/ /+/g'`
ZIP=`echo $ZIP | sed -e 's/ /+/g'`
PHONE=`echo $PHONE | sed -e 's/ /+/g'`
EMAIL=`echo $EMAIL | sed -e 's/ /+/g'`
ACCT=`echo $ACCT | sed -e 's/ /+/g'`
LEN=`echo "$FIRSTNAME$LASTNAME$ADDR$CITY$STATE$ZIP$PHONE$ACCT$EMAIL$PASS$PASS" | wc | awk '{print $3}' `
LEN=$(expr $LEN + 273)

[ x${LANGSUB} = x ] && LANGSUB=51AA9999
TNSITE=$SITE
TNPORT=80
[ x$http_proxy != x ] && TNSITE=$http_proxy
TNHOST=`echo $TNSITE | sed -e 's=http://\([^:/]*\)[:/].*=\1='`
(echo $TNSITE | grep >/dev/null 2>&1 '.*://.*:[0-9]') && TNPORT=`echo $TNSITE | sed -e 's=http://[^:]*:\([0-9][0-9]*\).*=\1='`
HOMEPAGE=`echo $HOMEPAGE | sed -e 's=\(.*\)/$=\1='`
SITE=`echo $SITE | sed -e 's=\(.*\)/$=\1='`
SUNPAGE=`echo $HOMEPAGE | sed -e 's=\(.*://[^/]*\).*=\1='`
FROMSITE=
[ x$http_proxy != x ] && FROMSITE=$SITE
export LEN FIRSTNAME LASTNAME ADDR CITY STATE COUNTRY ZIP PHONE ACCT PASS EMAIL FROMSITE
ftp -o index.html $HOMEPAGE
if grep 'A.*FREE.*' index.html >/dev/null 2>&1 ; then true; else
	echo 'getting index failed, answer was:'
	cat index.html
	exit 1
fi
FOO=`grep 'A.*FREE.*' index.html | sed -e 's/.*[hH][rR][eE][fF]="\(.*\)".*/\1/'`
ftp -o get.html $SUNPAGE$FOO
ftp -o Welcome.jhtml "$SITE/servlet/EComActionServlet?LMLoadBalanced=&LMLoadBalanced="
if grep action Welcome.jhtml >/dev/null 2>&1 ; then true; else
	echo 'getting welcome page failed, answer was:'
	cat Welcome.jhtml
	exit 1
fi
FOO=`grep action Welcome.jhtml | uniq | sed -e 's/.*"\(.*\)".*/\1/'`
export SESS=`echo $FOO | sed -e 's/.*sessionid$\(.*\)/\1/'`
SEDEX="-e s/@@@SESS@@@/$SESS/ -e s=@@@SITE@@@=$FROMSITE= -e s=@@@LANGSUB@@@=$LANGSUB="
( sleep 10 ; cat send.resp | sed $SEDEX ) | ( telnet $TNHOST $TNPORT ; sleep 15 ) >register.html 2>&1
#/bin/ksh ./sendreg.sh
( sleep 10 ; /bin/ksh ./sendreg.sh ; sleep 10 ) | ( telnet $TNHOST $TNPORT ; sleep 5 ) >regform.html 2>&1
if grep FREESTAR regform.html >/dev/null 2>&1 ; then true; else
	echo 'registration failed, answer was:'
	cat regform.html
	exit 1
fi
FOO=`grep FREESTAR regform.html | sed -e 's/.*"\(.*\)".*/\1/'`
ftp -o star.html $SITE$FOO
if grep STARLIN star.html >/dev/null 2>&1 ; then true; else
	echo 'login failed, answer was:'
	cat star.html
	exit 1
fi
FOO=`grep STARLIN star.html | sed -e 's/.*"\(.*\)".*/\1/'`
ftp -o order.html $SITE$FOO
( sleep 10 ; cat send.ord | sed $SEDEX ) | ( telnet $TNHOST $TNPORT ; sleep 10 ) >ordform.html 2>&1
( sleep 10 ; cat send.conf | sed $SEDEX ) | ( telnet $TNHOST $TNPORT ; sleep 10 ) >ordconf.html 2>&1
( sleep 10 ; cat send.agree | sed $SEDEX ) | ( telnet $TNHOST $TNPORT ; sleep 10 ) >agree.html 2>&1
( sleep 10 ; cat send.submit | sed $SEDEX ) | ( telnet $TNHOST $TNPORT ; sleep 10 ) >submit.html 2>&1
FOO=`grep "STRIL-${LANGSUB}" submit.html | head -1 | sed -e "s/.*href=.\(.*\)\'.*><.*/\1/"`
ftp -o ${DISTDIR}/${DISTFILE} "$FOO"
