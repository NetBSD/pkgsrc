# $NetBSD: Makefile,v 1.51 2010/02/10 18:11:46 joerg Exp $

DISTNAME=	sdr-3.0
PKGREVISION=	2
CATEGORIES=	mbone tk
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/3.0/

MAINTAINER=	is@NetBSD.org
HOMEPAGE=	http://www-mice.cs.ucl.ac.uk/multimedia/software/sdr/
COMMENT=	MBone Session Directory

PKG_DESTDIR_SUPPORT=	user-destdir

BROKEN=		Depends on TCL/TK 8.3

WRKSRC=		${WRKDIR}/sdr/${SYSDIR}
CRYPTO=		yes
USE_TOOLS+=	gmake
HAS_CONFIGURE=	yes

PKG_OPTIONS_VAR=	PKG_OPTIONS.sdr
PKG_SUPPORTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if exists(/usr/include/sys/inttypes.h)
EXTRA_FLAGS+=	-DHAVE_SYS_INTTYPES_H
MAKE_FLAGS+=	EXTRA_FLAGS=${EXTRA_FLAGS:Q}
.endif

.if ${OPSYS} == "SunOS"
SYSDIR= solaris
.else
SYSDIR= freebsd
.endif

INSTALLATION_DIRS=	bin

post-patch:
	${MV} ${WRKSRC}/../src/sdr.tcl ${WRKSRC}/../src/sdr.tcl.in &&	\
	${SED} -e 's|@PREFIX@|${PREFIX}|' ${WRKSRC}/../src/sdr.tcl.in >	\
		${WRKSRC}/../src/sdr.tcl

.if ${OPSYS} == "SunOS"
post-configure:
	# Untested for sdr 3.0 !!!
	${CAT}	${WRKSRC}/sdr/solaris/Makefile.solaris			\
		${WRKSRC}/sdr/src/Makefile.template			\
		> ${WRKSRC}/sdr/solaris/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sdr ${DESTDIR}${PREFIX}/bin/sdr

.include "../../mbone/common-mml/buildlink3.mk"
.include "../../x11/tk83/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
