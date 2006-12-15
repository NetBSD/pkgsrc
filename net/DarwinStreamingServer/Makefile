# $NetBSD: Makefile,v 1.1.1.1 2006/12/15 09:03:46 adam Exp $

DISTNAME=	DarwinStreamingSrvr5.5.4-Source
PKGNAME=	DarwinStreamingServer-5.5.4
CATEGORIES=	net multimedia
MASTER_SITES=	http://www.opensource.apple.com/projects/streaming/release/
EXTRACT_SUFX=	.tar

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://developer.apple.com/opensource/server/streaming/
COMMENT=	Open source version of Apple QuickTime Streaming Server

LICENSE=	apple-public-source-license
RESTRICTED=	Under APSL (see http://www.opensource.apple.com/apsl/).
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++

MAKE_FILE=	Makefile.POSIX
MAKE_ENV+=	CCOMP=${CC:Q} CPLUS=${CXX:Q} LINKER=${CXX:Q}
MAKE_ENV+=	COMPILER_FLAGS=${CFLAGS:Q} INCLUDE_FLAG="-include"
MAKE_ENV+=	CORE_LINK_LIBS="-pthread -lm -lcrypt -lstdc++"
MAKE_ENV+=	SHARED="-shared" MODULE_LIBS="-lgcc -lstdc++"

BUILD_DIRS=	CommonUtilitiesLib
BUILD_DIRS+=	QTFileLib
BUILD_DIRS+=	.
BUILD_DIRS+=	APIModules/QTSSRefMovieModule
BUILD_DIRS+=	APIModules/QTSSDemoAuthorizationModule.bproj
BUILD_DIRS+=	APIModules/QTSSRawFileModule.bproj
BUILD_DIRS+=	APIModules/QTSSSpamDefenseModule.bproj
BUILD_DIRS+=	APIModules/QTSSHomeDirectoryModule
BUILD_DIRS+=	StreamingProxy.tproj
BUILD_DIRS+=	qtpasswd.tproj
BUILD_DIRS+=	PlaylistBroadcaster.tproj
BUILD_DIRS+=	MP3Broadcaster
BUILD_DIRS+=	QTFileTools/QTBroadcaster.tproj
BUILD_DIRS+=	QTFileTools/QTFileInfo.tproj
BUILD_DIRS+=	QTFileTools/QTFileTest.tproj
BUILD_DIRS+=	QTFileTools/QTRTPFileTest.tproj
BUILD_DIRS+=	QTFileTools/QTRTPGen.tproj
BUILD_DIRS+=	QTFileTools/QTSDPGen.tproj
BUILD_DIRS+=	QTFileTools/QTSampleLister.tproj
BUILD_DIRS+=	QTFileTools/QTTrackInfo.tproj
BUILD_DIRS+=	StreamingLoadTool

INSTALLATION_DIRS+=	libexec/StreamingServerModules
INSTALLATION_DIRS+=	share/examples/streaming
INSTALLATION_DIRS+=	share/streaming
INSTALLATION_DIRS+=	share/streaming/AdminHtml
INSTALLATION_DIRS+=	share/streaming/AdminHtml/images
INSTALLATION_DIRS+=	share/streaming/AdminHtml/includes
INSTALLATION_DIRS+=	share/streaming/AdminHtml/html_en
INSTALLATION_DIRS+=	share/streaming/movies
INSTALLATION_DIRS+=	share/streaming/playlists

PKG_USERS=	qtss:qtss
PKG_GROUPS=	qtss
PKG_GECOS.qtss=	Darwin Streaming Server user

INTERACTIVE_STAGE=	fetch build

FETCH_MESSAGE=	"Darwin Streaming Server is available as a free download"
FETCH_MESSAGE+=	"under the APSL. Downloading the source code components"
FETCH_MESSAGE+=	"requires APSL registration."
FETCH_MESSAGE+=	"You should fetch the source code manually from"
FETCH_MESSAGE+=	"${MASTER_SITES}${DISTFILES} and put into"
FETCH_MESSAGE+=	"${DISTDIR}/${DISTFILES} directory."

REPLACE_PERL+=	WebAdmin/WebAdminHtml/broadcaster_lib.pl
REPLACE_PERL+=	WebAdmin/WebAdminHtml/parse_xml.cgi
REPLACE_PERL+=	WebAdmin/WebAdminHtml/playlist-lib.pl
REPLACE_PERL+=	WebAdmin/WebAdminHtml/relayxmlparser.pl
REPLACE_PERL+=	WebAdmin/WebAdminHtml/startplaylists.pl
REPLACE_PERL+=	WebAdmin/WebAdminHtml/view_broadcast.cgi
REPLACE_PERL+=	WebAdmin/src/streamingadminserver.pl
REPLACE_PERL+=	WinNTSupport/WinPasswdAssistant.pl

CONF_FILES=	${PKG_SYSCONFDIR:Q}/streaming/qtgroups ${PKG_SYSCONFDIR:Q}/streaming/qtgroups
CONF_FILES+=	${PKG_SYSCONFDIR:Q}/streaming/qtusers ${PKG_SYSCONFDIR:Q}/streaming/qtusers
CONF_FILES+=	${PKG_SYSCONFDIR:Q}/streaming/relayconfig.xml-Sample ${PKG_SYSCONFDIR:Q}/streaming/relayconfig.xml
CONF_FILES+=	${PKG_SYSCONFDIR:Q}/streaming/streamingloadtool.conf ${PKG_SYSCONFDIR:Q}/streaming/streamingloadtool.conf
CONF_FILES+=	${PKG_SYSCONFDIR:Q}/streaming/streamingserver.xml-POSIX ${PKG_SYSCONFDIR:Q}/streaming/streamingserver.xml

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	post-patch
SUBST_MESSAGE.makefile=	Fixing Makefiles
SUBST_FILES.makefile+=	APIModules/QTSSDemoAuthorizationModule.bproj/Makefile.POSIX
SUBST_FILES.makefile+=	APIModules/QTSSHomeDirectoryModule/Makefile.POSIX
SUBST_FILES.makefile+=	APIModules/QTSSRawFileModule.bproj/Makefile.POSIX
SUBST_FILES.makefile+=	APIModules/QTSSRefMovieModule/Makefile.POSIX
SUBST_FILES.makefile+=	APIModules/QTSSSpamDefenseModule.bproj/Makefile.POSIX
SUBST_FILES.makefile+=	CommonUtilitiesLib/Makefile.POSIX
SUBST_FILES.makefile+=	HTTPUtilitiesLib/Makefile.POSIX
SUBST_FILES.makefile+=	MP3Broadcaster/Makefile.POSIX
SUBST_FILES.makefile+=	Makefile.POSIX
SUBST_FILES.makefile+=	PlaylistBroadcaster.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	QTFileLib/Makefile.POSIX
SUBST_FILES.makefile+=	QTFileTools/QTBroadcaster.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	QTFileTools/QTFileInfo.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	QTFileTools/QTFileTest.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	QTFileTools/QTRTPFileTest.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	QTFileTools/QTRTPGen.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	QTFileTools/QTSDPGen.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	QTFileTools/QTSampleLister.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	QTFileTools/QTTrackInfo.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	StreamingLoadTool/Makefile.POSIX
SUBST_FILES.makefile+=	StreamingProxy.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	qtpasswd.tproj/Makefile.POSIX
SUBST_SED.makefile+=	-e "s|-O[23]||"

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Fixing paths
SUBST_FILES.path+=	defaultPaths.h
SUBST_FILES.path+=	WebAdmin/src/streamingadminserver.pl
SUBST_FILES.path+=	streamingserver.xml-POSIX
SUBST_SED.path+=	-e "s|/etc/streaming|${PKG_SYSCONFDIR}/streaming|"
SUBST_SED.path+=	-e "s|/movies|/share/streaming/movies|"
SUBST_SED.path+=	-e "s|/usr/local|${PREFIX}|"
SUBST_SED.path+=	-e "s|/sbin/StreamingServer|libexec/StreamingServer|"
SUBST_SED.path+=	-e "s|/var/streaming/AdminHtml|${PREFIX}/share/streaming/AdminHtml|"
SUBST_SED.path+=	-e "s|/var/streaming/playlists|${PREFIX}/share/streaming/playlists|"
SUBST_SED.path+=	-e "s|/var/streaming/logs|${VARBASE}/log/streaming|"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_MESSAGE.conf=	Fixing configuration file
SUBST_FILES.conf+=	WebAdmin/streamingadminserver.conf
SUBST_SED.conf+=	-e "s|/Library/QuickTimeStreaming/AdminHtml|${PREFIX}/share/streaming/AdminHtml|"
SUBST_SED.conf+=	-e "s|/Library/QuickTimeStreaming/playlists|${PREFIX}/share/streaming/playlists|"
SUBST_SED.conf+=	-e "s|/Library/QuickTimeStreaming/Logs|${VARBASE}/log/streaming|"
SUBST_SED.conf+=	-e "s|/usr/sbin/QuickTime|${PREFIX}/sbin/Darwin|"

post-extract:
	rm -rf ${WRKSRC}/*PackageMetaData

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DarwinStreamingServer ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/PlaylistBroadcaster.tproj/PlaylistBroadcaster ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/MP3Broadcaster/MP3Broadcaster ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/qtpasswd.tproj/qtpasswd ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/APIModules/QTSSHomeDirectoryModule/QTSSHomeDirectoryModule ${PREFIX}/libexec/StreamingServerModules
	${INSTALL_PROGRAM} ${WRKSRC}/APIModules/QTSSRefMovieModule/QTSSRefMovieModule ${PREFIX}/libexec/StreamingServerModules
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTBroadcaster.tproj/QTBroadcaster ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTFileTest.tproj/QTFileTest ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTRTPFileTest.tproj/QTRTPFileTest ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTRTPGen.tproj/QTRTPGen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTSampleLister.tproj/QTSampleLister ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTSDPGen.tproj/QTSDPGen ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTTrackInfo.tproj/QTTrackInfo ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/APIModules/QTSSHomeDirectoryModule/createuserstreamingdir ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/streamingserver.xml-POSIX ${PREFIX}/share/examples/streaming
	${INSTALL_DATA} ${WRKSRC}/relayconfig.xml-Sample ${PREFIX}/share/examples/streaming
	${INSTALL_DATA} ${WRKSRC}/qtusers ${PREFIX}/share/examples/streaming
	${INSTALL_DATA} ${WRKSRC}/qtgroups ${PREFIX}/share/examples/streaming
	${INSTALL_DATA}	${WRKSRC}/Documentation/readme.txt ${PREFIX}/share/streaming
	${INSTALL_DATA}	${WRKSRC}/Documentation/3rdPartyAcknowledgements.rtf ${PREFIX}/share/streaming
	${INSTALL_PROGRAM} ${WRKSRC}/StreamingLoadTool/StreamingLoadTool ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/StreamingLoadTool/streamingloadtool.conf ${PREFIX}/share/examples/streaming
	${INSTALL_SCRIPT} ${WRKSRC}/WebAdmin/src/streamingadminserver.pl ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/*.pl ${PREFIX}/share/streaming/AdminHtml
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/*.cgi ${PREFIX}/share/streaming/AdminHtml
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/*.html ${PREFIX}/share/streaming/AdminHtml
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/images/*.gif ${PREFIX}/share/streaming/AdminHtml/images
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/includes/*.js ${PREFIX}/share/streaming/AdminHtml/includes
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/html_en/messages ${PREFIX}/share/streaming/AdminHtml/html_en
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/html_en/genres ${PREFIX}/share/streaming/AdminHtml/html_en
	${INSTALL_DATA} ${WRKSRC}/sample* ${PREFIX}/share/streaming/movies

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
