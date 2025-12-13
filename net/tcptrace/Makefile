# $NetBSD: Makefile,v 1.37 2025/12/13 16:42:03 vins Exp $

DISTNAME=	tcptrace-6.6.7
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	https://distfiles.macports.org/tcptrace/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/open-tcptrace/
COMMENT=	TCP dump file analysis tool
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=		yes

USE_TOOLS+=		bison flex

BUILD_TARGET=		tcptrace

PKGDOCS=		COPYRIGHT FAQ README README.tput_graphs README.tline_graphs

LIBS+=			-lpcap -lm
LIBS.SunOS+=		-lnsl -lsocket

SUBST_CLASSES+=		pkgsrc
SUBST_STAGE.pkgsrc=	pre-configure
SUBST_FILES.pkgsrc=	Makefile.in
SUBST_VARS.pkgsrc+=	HOST PREFIX PKGMANDIR USER
SUBST_MESSAGE.pkgsrc=	Replacing pkgsrc placeholders

SUBST_CLASSES+=		hacks
SUBST_STAGE.hacks=	pre-configure
SUBST_FILES.hacks=	erf.c gcache.c ipv6.c netscout.c \
			print.c trace.c tcpdump.c tcptrace.c
SUBST_SED.hacks=	-e 's|memcpy|_memcpy|g'

MAKE_FLAGS+=		LDLIBS=${LIBS:M*:Q}

AUTO_MKDIRS=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tcptrace		\
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/tcptrace.man		\
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tcptrace.1
	${INSTALL_DATA}  ${PKGDOCS:S|^|${WRKSRC}/|}	\
		${DESTDIR}${PREFIX}/share/doc/tcptrace
	${INSTALL_DATA} ${WRKSRC}/dot_tcptracerc	\
		${DESTDIR}${PREFIX}/share/examples/tcptracerc

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
