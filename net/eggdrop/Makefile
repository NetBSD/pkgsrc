# $NetBSD: Makefile,v 1.1 1998/11/24 04:12:07 tv Exp $
#

DISTNAME=	eggdrop1.3.22
PKGNAME=	eggdrop-1.3.22
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.sodre.net/pub/eggdrop/ \
		ftp://ftp.bots.org/pub/mirrors/eggdrop/ \
		ftp://ftp.gymnet.com/pub/irc/bots/eggdrop/

MAINTAINER=     tv@netbsd.org
HOMEPAGE=	http://www.sodre.net/eggdrop/

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	TCLLIB="${PREFIX}/lib" TCLINC="${PREFIX}/include/tcl8.0"

post-patch:
	cd ${WRKSRC} && ${SED} -e 's,modules/,${PREFIX}/lib/eggdrop/,' \
		< eggdrop.conf.dist > eggdrop.conf.dist.new

do-install: do-install-program
do-install-program:
	${INSTALL_PROGRAM} ${WRKSRC}/eggdrop ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/doc/man1/eggdrop.1 ${PREFIX}/man/man1/
	${INSTALL_DATA} ${WRKSRC}/eggdrop.conf.dist.new ${PREFIX}/etc/eggdrop.conf.dist
	${INSTALL_DATA_DIR} ${PREFIX}/share/eggdrop \
		${PREFIX}/share/eggdrop/help ${PREFIX}/share/eggdrop/language \
		${PREFIX}/share/eggdrop/scripts \
		${PREFIX}/share/eggdrop/help/msg ${PREFIX}/share/eggdrop/help/set
	${INSTALL_DATA} ${WRKSRC}/language/core.english.lang \
		${PREFIX}/share/eggdrop/language/
	cd ${WRKSRC}/doc && ${INSTALL_DATA} BOTNET eggdrop.doc \
		tcl-commands.doc tricks ${PREFIX}/share/eggdrop/
	cd ${WRKSRC}/help && ${INSTALL_DATA} assoc.help chaninfo \
		channels.help cmds1.help cmds2.help console.help core.help \
		filesys.help irc.help notes.help seen.help server.help \
		share.help userinfo.help \
		${PREFIX}/share/eggdrop/help/
	cd ${WRKSRC}/help/msg && ${INSTALL_DATA} irc.help notes.help \
		seen.help userinfo.help \
		${PREFIX}/share/eggdrop/help/msg/
	cd ${WRKSRC}/help/set && ${INSTALL_DATA} channels.help cmds1.help \
		cmds2.help console.help ctcp.help filesys.help irc.help \
		notes.help server.help transfer.help \
		${PREFIX}/share/eggdrop/help/set/
	cd ${WRKSRC}/scripts && ${INSTALL_DATA} CONTENTS action.fix.tcl \
		alltools.tcl botchk compat.tcl getops-2.0.1.tcl klined.tcl \
		notes2.tcl ques4.tcl userinfo1.0.tcl weed \
		${PREFIX}/share/eggdrop/scripts/

.include "../../mk/bsd.pkg.mk"

.if defined(NOPIC)
ALL_TARGET=	static
.else
do-install: do-install-modules
do-install-modules:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/eggdrop
	cd ${WRKSRC} && ${INSTALL_DATA} assoc.so blowfish.so channels.so \
		console.so ctcp.so filesys.so irc.so notes.so seen.so \
		server.so share.so transfer.so wire.so woobie.so \
		${PREFIX}/lib/eggdrop/
.endif
