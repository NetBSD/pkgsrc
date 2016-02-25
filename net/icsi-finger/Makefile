# $NetBSD: Makefile,v 1.29 2016/02/25 16:20:51 jperkin Exp $
#

DISTNAME=	icsi-finger-1.0.29
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.icsi.berkeley.edu/pub/ai/stolcke/software/
MASTER_SITES+=	http://ftp.sunet.se/pub/nir/finger/icsi-finger/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	is@NetBSD.org
COMMENT=	Distributed finger service

WRKSRC=		${WRKDIR}/finger

# the following only used as installation destinations!
XMPLD=		${DESTDIR}${PREFIX}/share/examples/icsi-finger
XMPLDT=		${XMPLD}/targets

INSTALLATION_DIRS=	bin libexec sbin
INSTALLATION_DIRS+=	${PKGMANDIR}/man1 ${PKGMANDIR}/man5 ${PKGMANDIR}/man8
INSTALLATION_DIRS+=	share/examples/icsi-finger/targets

TOOL_DEPENDS+=	tradcpp-[0-9]*:../../devel/tradcpp

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_COMPILER:Mclang)
CPPFLAGS+=	-Wno-error=return-type
.endif

MAKE_ENV.SunOS+=	CPP_ARGS=-DSVR4

pre-configure:
		chmod +w ${WRKSRC}/config.h
		${ECHO} \#define ManDir ${PREFIX}/${PKGMANDIR} >> \
			${WRKSRC}/config.h
		${ECHO} \#define TARGETDIR \"${PKG_SYSCONFDIR}/fingerdir/targets\"\
			>> ${WRKSRC}/config.h
		${ECHO} \#define TargetDir ${PKG_SYSCONFDIR}/fingerdir/targets \
			>> ${WRKSRC}/config.h
		${ECHO} \#define TTYLOCFILE \"${PKG_SYSCONFDIR}/fingerdir/ttylocs\" \
			>> ${WRKSRC}/config.h
		${ECHO} \#define HOSTCONFIGFILE \"${PKG_SYSCONFDIR}/fingerdir/hostconfig\" \
			>> ${WRKSRC}/config.h
		${MV} -f ${WRKSRC}/support/inetd.conf-add \
			${WRKSRC}/support/inetd.conf-add.bak
		${SED}	-e s@/usr/local/etc@${PREFIX}/libexec@      \
			-e s@/usr/local/etc@${PREFIX}/libexec@      \
			${WRKSRC}/support/inetd.conf-add.bak > \
			${WRKSRC}/support/inetd.conf-add
		${MV} -f ${WRKSRC}/support/rc.local-add \
			${WRKSRC}/support/rc.local-add.bak
		${SED}  -e s@/usr/local/bin/@${PREFIX}/sbin/g@      \
			${WRKSRC}/support/rc.local-add.bak > \
			${WRKSRC}/support/rc.local-add
		for i in ${WRKSRC}/src/targets/x-.busy \
			${WRKSRC}/src/targets/x-.down; do \
			${MV} $$i $$i.bak; ${SED} -e s@nawk@awk@ \
				-e s@/usr/local/etc@${PREFIX}/libexec@ \
				$$i.bak > $$i ; \
			${RM} -f $$i.bak ; \
		done

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/src/finger ${DESTDIR}${PREFIX}/bin/gfinger
		${INSTALL_PROGRAM} ${WRKSRC}/src/fingerd ${DESTDIR}${PREFIX}/sbin/gfingerd
		${INSTALL_SCRIPT} ${WRKSRC}/src/vifinger ${DESTDIR}${PREFIX}/sbin
		${INSTALL_PROGRAM} ${WRKSRC}/src/packet2ascii ${DESTDIR}${PREFIX}/sbin
		${LN} -sf packet2ascii ${DESTDIR}${PREFIX}/sbin/ascii2packet
		${INSTALL_PROGRAM} ${WRKSRC}/src/in.fingerd ${DESTDIR}${PREFIX}/libexec
		${INSTALL_PROGRAM} ${WRKSRC}/src/in.cfingerd ${DESTDIR}${PREFIX}/libexec
		${INSTALL_PROGRAM} ${WRKSRC}/src/in.cfingerd ${DESTDIR}${PREFIX}/libexec
		${INSTALL_SCRIPT_DIR} ${DESTDIR}${PREFIX}/etc/fingerdir/targets
		${INSTALL_DATA} ${WRKSRC}/support/ttylocs ${XMPLD}
		${INSTALL_DATA} ${WRKSRC}/support/hostconfig ${XMPLD}
		${INSTALL_DATA} ${WRKSRC}/support/rc.local-add ${XMPLD}
		${INSTALL_DATA} ${WRKSRC}/support/services-add ${XMPLD}
		${INSTALL_DATA} ${WRKSRC}/support/inetd.conf-add ${XMPLD}
		(cd ${WRKSRC}/src; ${MAKE} install.man DESTDIR=${DESTDIR} \
			INSTALLMAN=${INSTALL_MAN:Q})
		(cd ${WRKSRC}/src; ${MAKE} TARGETD=${XMPLDT} install.targets \
			INSTALLSCRIPT=${INSTALL_SCRIPT:Q})

.include "../../mk/bsd.pkg.mk"
