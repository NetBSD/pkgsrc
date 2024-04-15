# $NetBSD: Makefile,v 1.24 2024/04/15 16:24:52 schmonz Exp $

DISTNAME=		fehQlibs-23
PKGNAME=		${DISTNAME:S/Qlibs-/qlibs-/}
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		https://www.fehcom.de/ipnet/fehQlibs/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://www.fehcom.de/ipnet/qlibs.html
COMMENT=		State-of-the-art C routines for Internet services
LICENSE=		public-domain

MAKE_JOBS_SAFE=		no
USE_LIBTOOL=		yes

BUILD_TARGET=		libs shared

REPLACE_SH=		configure install

SUBST_CLASSES+=		echo
SUBST_STAGE.echo=	pre-configure
SUBST_FILES.echo=	configure install
SUBST_SED.echo=		-e 's|echo -n|${ECHO_N}|g'
SUBST_NOOP_OK.echo=	yes # ECHO_N may be "echo -n"

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	do-configure
SUBST_FILES.etc=	dnsstub/dns_rcrw.c
SUBST_SED.etc=		-e 's|/etc/dnsrewrite|${PKG_SYSCONFBASE}/dnsrewrite|g'

SUBST_CLASSES+=		libtool
SUBST_STAGE.libtool=	pre-configure
SUBST_FILES.libtool=	Makefile
SUBST_SED.libtool=	-e 's|\$$(MAKELIB) \$$(LDFLAGS) |$$(MAKELIB) |g'
SUBST_SED.libtool+=	-e 's|\.o|\.lo|g'

BUILD_DEFS+=		PKG_SYSCONFBASE

do-configure:
	cd ${WRKSRC};								\
	${ECHO} "LIBDIR=${DESTDIR}${PREFIX}/lib/qlibs" >> ${WRKSRC}/conf-build;	\
	${ECHO} "HDRDIR=${DESTDIR}${PREFIX}/include/qlibs" >> ${WRKSRC}/conf-build; \
	${MAKE} check

post-install:
	cd ${WRKSRC} && for lib in *.la; do \
		${LIBTOOL} --mode=install ${INSTALL_LIB} $${lib} \
			${DESTDIR}${PREFIX}/lib/qlibs; \
	done

.include "../../mk/bsd.pkg.mk"
