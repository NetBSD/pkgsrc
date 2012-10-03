# $NetBSD: Makefile,v 1.35 2012/10/03 00:02:35 asau Exp $

DISTNAME=	eggdrop1.6.21
PKGNAME=	eggdrop-1.6.21
#KGREVISION=	1
PKGREVISION=	1
CATEGORIES=	chat
MASTER_SITES=	ftp://ftp.eggheads.org/pub/eggdrop/source/1.6/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.eggheads.org/
COMMENT=	IRC robot with TCL scripting and multi-channel ability

MAKE_JOBS_SAFE=	no

PLIST_VARS=		dynamic
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		TCLLIB="${PREFIX}/lib" TCLINC="${PREFIX}/include"

.include "../../mk/bsd.prefs.mk"
.if !empty(PKGSRC_COMPILER:Msunpro)
# fix for PR#44382
CONFIGURE_ENV+=         ac_cv_c_inline=
.endif

EGDIR=		${PREFIX}/share/examples/eggdrop
CONF_FILES=	${EGDIR}/eggdrop.conf ${PKG_SYSCONFDIR}/eggdrop.conf

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-patch:
	cd ${WRKSRC} && ${SED} -e 's,modules/,${PREFIX}/lib/eggdrop/,' \
		< eggdrop.conf > eggdrop.conf.dist.new

post-configure:
	cd ${WRKSRC} && ${MAKE} config

do-install: do-install-program
do-install-program:
	${INSTALL_PROGRAM} ${WRKSRC}/eggdrop ${DESTDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/man1/eggdrop.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/eggdrop.conf.dist.new \
		${DESTDIR}${EGDIR}/eggdrop.conf
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/eggdrop/html
	cd ${WRKSRC}/doc/html && ${INSTALL_DATA} *.html \
		${DESTDIR}${PREFIX}/share/doc/eggdrop/html
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/eggdrop
	cd ${WRKSRC}/doc && ${INSTALL_DATA} BANS BOTNET FIRST-SCRIPT MODULES \
		PARTYLINE USERS TRICKS TEXT-SUBSTITUTIONS tcl-commands.doc \
		${DESTDIR}${PREFIX}/share/doc/eggdrop
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/eggdrop
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/eggdrop/help
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/eggdrop/language
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/eggdrop/scripts
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/eggdrop/help/msg
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/eggdrop/help/set
	${INSTALL_DATA} ${WRKSRC}/language/core.*.lang \
		${DESTDIR}${PREFIX}/share/eggdrop/language/
	cd ${WRKSRC}/help && ${INSTALL_DATA} cmds1.help cmds2.help core.help \
		${DESTDIR}${PREFIX}/share/eggdrop/help/
	cd ${WRKSRC}/help/set && ${INSTALL_DATA} cmds1.help \
		${DESTDIR}${PREFIX}/share/eggdrop/help/set/
	cd ${WRKSRC}/scripts && ${INSTALL_DATA} CONTENTS *.tcl autobotchk \
		 botchk weed ${DESTDIR}${PREFIX}/share/eggdrop/scripts/

.include "../../lang/tcl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

.if defined(NOPIC)
BUILD_TARGET=	static
.else
BUILD_TARGET=	eggdrop
PLIST.dynamic=	yes
do-install: do-install-modules
do-install-modules:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/lib/eggdrop
	cd ${WRKSRC} && ${INSTALL_DATA} assoc.so blowfish.so channels.so \
		compress.so console.so ctcp.so dns.so filesys.so irc.so notes.so \
		seen.so server.so share.so transfer.so uptime.so wire.so \
		${DESTDIR}${PREFIX}/lib/eggdrop
	cd ${WRKSRC}/src/mod && ${FIND} . -name "*.lang" -exec ${INSTALL_DATA} "{}" \
		${DESTDIR}${PREFIX}/share/eggdrop/language ";"
.endif
