# $NetBSD: Makefile,v 1.12 2013/03/24 16:51:07 joerg Exp $

DISTNAME=	DarwinStreamingSrvr5.5.5-Source
PKGNAME=	DarwinStreamingServer-5.5.5
PKGREVISION=	4
CATEGORIES=	net multimedia
MASTER_SITES=	http://static.macosforge.org/dss/downloads/

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://dss.macosforge.org/
COMMENT=	Open source version of Apple QuickTime Streaming Server
LICENSE=	apple-public-source-license

MAKE_JOBS_SAFE=	no

RESTRICTED=	Under APSL (see http://www.opensource.apple.com/apsl/).
NO_BIN_ON_CDROM=${RESTRICTED}
NO_BIN_ON_FTP=	${RESTRICTED}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=	c c++

MAKE_FILE=	Makefile.POSIX
MAKE_ENV+=	CCOMP=${CC:Q} CPLUS=${CXX:Q}\ -fPIC LINKER=${CXX:Q}
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

INSTALLATION_DIRS+=	bin sbin
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

REPLACE_PERL+=	WebAdmin/WebAdminHtml/broadcaster_lib.pl
REPLACE_PERL+=	WebAdmin/WebAdminHtml/parse_xml.cgi
REPLACE_PERL+=	WebAdmin/WebAdminHtml/playlist-lib.pl
REPLACE_PERL+=	WebAdmin/WebAdminHtml/relayxmlparser.pl
REPLACE_PERL+=	WebAdmin/WebAdminHtml/startplaylists.pl
REPLACE_PERL+=	WebAdmin/WebAdminHtml/view_broadcast.cgi
REPLACE_PERL+=	WebAdmin/src/streamingadminserver.pl
REPLACE_PERL+=	WinNTSupport/WinPasswdAssistant.pl

REQUIRE_DIRS+=	${PKG_SYSCONFDIR}/streaming
CONF_FILES=	share/examples/streaming/qtgroups ${PKG_SYSCONFDIR}/streaming/qtgroups
CONF_FILES+=	share/examples/streaming/qtusers ${PKG_SYSCONFDIR}/streaming/qtusers
CONF_FILES+=	share/examples/streaming/relayconfig.xml-Sample ${PKG_SYSCONFDIR}/streaming/relayconfig.xml
CONF_FILES+=	share/examples/streaming/streamingserver.xml-POSIX ${PKG_SYSCONFDIR}/streaming/streamingserver.xml

SUBST_CLASSES+=		makefile
SUBST_STAGE.makefile=	post-patch
SUBST_MESSAGE.makefile=	Fixing Makefiles
SUBST_FILES.makefile+=	APIModules/QTSSDemoAuthorizationModule.bproj/Makefile.POSIX
SUBST_FILES.makefile+=	APIModules/QTSSHomeDirectoryModule/Makefile.POSIX
SUBST_FILES.makefile+=	APIModules/QTSSRawFileModule.bproj/Makefile.POSIX
SUBST_FILES.makefile+=	APIModules/QTSSRefMovieModule/Makefile.POSIX
SUBST_FILES.makefile+=	APIModules/QTSSSpamDefenseModule.bproj/Makefile.POSIX
SUBST_FILES.makefile+=	APIStubLib/makefile.apistublib.POSIX
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
SUBST_FILES.makefile+=	StreamingProxy.tproj/Makefile.POSIX
SUBST_FILES.makefile+=	qtpasswd.tproj/Makefile.POSIX
SUBST_SED.makefile+=	-e "s|-O[023]||"

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_MESSAGE.path=	Fixing paths
SUBST_FILES.path+=	defaultPaths.h
SUBST_FILES.path+=	WebAdmin/src/streamingadminserver.pl
SUBST_FILES.path+=	streamingserver.xml-POSIX
SUBST_SED.path+=	-e "s|/etc/streaming|${PKG_SYSCONFDIR}/streaming|"
SUBST_SED.path+=	-e "s|/movies|/share/streaming/movies|"
SUBST_SED.path+=	-e "s|/usr/local|${PREFIX}|"
SUBST_SED.path+=	-e "s|/sbin/StreamingServer|/libexec/StreamingServer|"
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
	${INSTALL_PROGRAM} ${WRKSRC}/DarwinStreamingServer ${DESTDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/PlaylistBroadcaster.tproj/PlaylistBroadcaster ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/MP3Broadcaster/MP3Broadcaster ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/qtpasswd.tproj/qtpasswd ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/APIModules/QTSSHomeDirectoryModule/QTSSHomeDirectoryModule ${DESTDIR}${PREFIX}/libexec/StreamingServerModules
	${INSTALL_PROGRAM} ${WRKSRC}/APIModules/QTSSRefMovieModule/QTSSRefMovieModule ${DESTDIR}${PREFIX}/libexec/StreamingServerModules
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTBroadcaster.tproj/QTBroadcaster ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTFileTest.tproj/QTFileTest ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTRTPFileTest.tproj/QTRTPFileTest ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTRTPGen.tproj/QTRTPGen ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTSampleLister.tproj/QTSampleLister ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTSDPGen.tproj/QTSDPGen ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QTFileTools/QTTrackInfo.tproj/QTTrackInfo ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/APIModules/QTSSHomeDirectoryModule/createuserstreamingdir ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/streamingserver.xml-POSIX ${DESTDIR}${PREFIX}/share/examples/streaming
	${INSTALL_DATA} ${WRKSRC}/relayconfig.xml-Sample ${DESTDIR}${PREFIX}/share/examples/streaming
	${INSTALL_DATA} ${WRKSRC}/qtusers ${DESTDIR}${PREFIX}/share/examples/streaming
	${INSTALL_DATA} ${WRKSRC}/qtgroups ${DESTDIR}${PREFIX}/share/examples/streaming
	${INSTALL_DATA}	${WRKSRC}/Documentation/readme.txt ${DESTDIR}${PREFIX}/share/streaming
	${INSTALL_DATA}	${WRKSRC}/Documentation/3rdPartyAcknowledgements.rtf ${DESTDIR}${PREFIX}/share/streaming
	${INSTALL_SCRIPT} ${WRKSRC}/WebAdmin/src/streamingadminserver.pl ${DESTDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/*.pl ${DESTDIR}${PREFIX}/share/streaming/AdminHtml
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/*.cgi ${DESTDIR}${PREFIX}/share/streaming/AdminHtml
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/*.html ${DESTDIR}${PREFIX}/share/streaming/AdminHtml
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/images/*.gif ${DESTDIR}${PREFIX}/share/streaming/AdminHtml/images
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/includes/*.js ${DESTDIR}${PREFIX}/share/streaming/AdminHtml/includes
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/html_en/messages ${DESTDIR}${PREFIX}/share/streaming/AdminHtml/html_en
	${INSTALL_DATA} ${WRKSRC}/WebAdmin/WebAdminHtml/html_en/genres ${DESTDIR}${PREFIX}/share/streaming/AdminHtml/html_en
	${INSTALL_DATA} ${WRKSRC}/sample* ${DESTDIR}${PREFIX}/share/streaming/movies

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
