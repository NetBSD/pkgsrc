# $NetBSD: Makefile,v 1.39 2016/03/05 11:28:45 jperkin Exp $
#

DISTNAME=	alpine-2.11
PKGREVISION=	5
CATEGORIES=	mail
MASTER_SITES=	http://patches.freeiz.com/alpine/release/src/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://patches.freeiz.com/alpine/release/
COMMENT=	Program for Internet News and E-mail
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --with-ssl-dir=${SSLBASE}
CONFIGURE_ARGS+= --with-ssl-certs-dir=${SSLCERTS:Q}
CONFIGURE_ARGS+= --with-ssl-include-dir=${SSLBASE}/include
CONFIGURE_ARGS+= --with-ssl-lib-dir=${SSLBASE}/lib
CONFIGURE_ARGS+= --with-system-pinerc=${PKG_SYSCONFDIR}/pine.conf
CONFIGURE_ARGS+= --with-system-fixed-pinerc=${PKG_SYSCONFDIR}/pine.conf.fixed
CONFIGURE_ARGS+= --with-passfile=.pine-passfile
# disabled, for Web Alpine Support
CONFIGURE_ARGS+=	--without-tcl

USE_LIBTOOL=	yes

MAKE_JOBS_SAFE=         no
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && empty(OS_VERSION:M4.99.*) && empty(OS_VERSION:M[5-9]*)
CONFIGURE_ARGS+= --without-pthread
.endif

# mach/mach.h defines panic, differently.
SUBST_CLASSES.Darwin+=	panic
SUBST_STAGE.panic=	pre-configure
SUBST_MESSAGE.panic=	Renaming the panic function
SUBST_FILES.panic=	*/*.c
SUBST_FILES.panic+=	pith/util.h
SUBST_SED.panic+=	-e 's,panic(,Panic(,g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alpine/alpine ${DESTDIR}${PREFIX}/bin/alpine
	${INSTALL_MAN} ${WRKSRC}/doc/alpine.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alpine.1

.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
