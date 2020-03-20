# $NetBSD: Makefile,v 1.12 2020/03/20 19:52:23 rillig Exp $

DISTNAME=		fehQlibs-14
PKGNAME=		${DISTNAME:S/Qlibs-/qlibs-0.9./}
CATEGORIES=		net
MASTER_SITES=		https://www.fehcom.de/ipnet/fehQlibs/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.fehcom.de/ipnet/qlibs.html
COMMENT=		State-of-the-art C routines for Internet services
LICENSE=		public-domain

MAKE_JOBS_SAFE=		no

BUILD_TARGET=		libs shared

SUBST_CLASSES+=		echo
SUBST_STAGE.echo=	pre-configure
SUBST_FILES.echo=	configure install
SUBST_SED.echo=		-e 's|echo -n|${ECHO_N}|g'
SUBST_NOOP_OK.echo=	yes # ECHO_N may be "echo -n"

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	dnsstub/dns_rcrw.c
SUBST_SED.etc=		-e 's|/etc/dnsrewrite|${PKG_SYSCONFBASE}/dnsrewrite|g'

SUBST_CLASSES+=		ldflags
SUBST_STAGE.ldflags=	pre-configure
SUBST_FILES.ldflags=	Makefile
SUBST_SED.ldflags=	-e 's|\$$(MAKELIB) \$$(LDFLAGS) |$$(MAKELIB) |g'

BUILD_DEFS+=		PKG_SYSCONFBASE

post-extract:
	rm -f ${WRKSRC}/include/*.orig

do-configure:
	cd ${WRKSRC};								\
	${ECHO} "LIBDIR=${DESTDIR}${PREFIX}/lib/qlibs" >> ${WRKSRC}/conf-build;	\
	${ECHO} "HDRDIR=${DESTDIR}${PREFIX}/include/qlibs" >> ${WRKSRC}/conf-build; \
	${MAKE} check

.include "../../mk/bsd.prefs.mk"

post-build:
.if ${OPSYS} == Darwin
	cd ${WRKSRC} && for lib in *.so; do \
	  install_name_tool -id ${PREFIX}/lib/qlibs/$${lib} $${lib}; \
	done
.endif

.include "../../mk/bsd.pkg.mk"
