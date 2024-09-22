# $NetBSD: Makefile,v 1.26 2024/09/22 18:22:49 schmonz Exp $

DISTNAME=		fehQlibs-25b
PKGNAME=		${DISTNAME:S/Qlibs-/qlibs-/}
CATEGORIES=		net
MASTER_SITES=		https://www.fehcom.de/ipnet/fehQlibs/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.fehcom.de/ipnet/qlibs.html
COMMENT=		State-of-the-art C routines for Internet services
LICENSE=		public-domain

WRKSRC=			${WRKDIR}/${DISTNAME:C/b$//}

MAKE_JOBS_SAFE=		no
USE_LIBTOOL=		yes
HAS_CONFIGURE=		yes

BUILD_TARGET=		libs shared
BUILD_DIRS=		src

REPLACE_SH=		configure install

SUBST_CLASSES+=		echo
SUBST_STAGE.echo=	pre-configure
SUBST_FILES.echo=	configure install
SUBST_SED.echo=		-e 's|echo -n|${ECHO_N}|g'
SUBST_NOOP_OK.echo=	yes # ECHO_N may be "echo -n"

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	src/dnsstub/dns_rcrw.c
SUBST_SED.etc=		-e 's|/etc/dnsrewrite|${PKG_SYSCONFBASE}/dnsrewrite|g'

SUBST_CLASSES+=		libtool
SUBST_STAGE.libtool=	pre-configure
SUBST_FILES.libtool=	src/Makefile
SUBST_SED.libtool=	-e 's|\$$(MAKELIB) \$$(LDFLAGS) |$$(MAKELIB) |g'
SUBST_SED.libtool+=	-e 's|\.o|\.lo|g'

BUILD_DEFS+=		PKG_SYSCONFBASE

pre-configure:
	${ECHO} "LIBDIR=${DESTDIR}${PREFIX}/lib/qlibs" >> ${WRKSRC}/conf-build;	\
	${ECHO} "HDRDIR=${DESTDIR}${PREFIX}/include/qlibs" >> ${WRKSRC}/conf-build

post-install:
	cd ${WRKSRC}/src && for lib in *.la; do \
		${LIBTOOL} --mode=install ${INSTALL_LIB} $${lib} \
			${DESTDIR}${PREFIX}/lib/qlibs; \
	done

.include "../../mk/bsd.pkg.mk"
