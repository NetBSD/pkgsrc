# $NetBSD: Makefile,v 1.48 2021/10/17 09:49:09 nia Exp $

DISTNAME=	alpine-2.25
CATEGORIES=	mail
MASTER_SITES=	http://alpine.x10host.com/alpine/release/src/
DIST_SUBDIR=	${DISTNAME}
EXTRACT_SUFX=	.tar.xz

PATCH_SITES=		https://alpine.x10host.com/alpine/patches/alpine-${PKGVERSION_NOREV}/
PATCHFILES+=		maildir.patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://alpine.x10host.com/index.html
COMMENT=	Program for Internet News and E-mail
LICENSE=	apache-2.0

GNU_CONFIGURE=	yes
USE_TOOLS+=	msgfmt msgmerge xgettext
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=	--with-ssl-dir=${SSLBASE}
CONFIGURE_ARGS+=	--with-ssl-certs-dir=${SSLCERTS:Q}
CONFIGURE_ARGS+=	--with-ssl-include-dir=${SSLBASE}/include
CONFIGURE_ARGS+=	--with-ssl-lib-dir=${SSLBASE}/lib
CONFIGURE_ARGS+=	--with-system-pinerc=${PKG_SYSCONFDIR}/pine.conf
CONFIGURE_ARGS+=	--with-system-fixed-pinerc=${PKG_SYSCONFDIR}/pine.conf.fixed
CONFIGURE_ARGS+=	--with-passfile=.pine-passfile
# disabled, for Web Alpine Support
CONFIGURE_ARGS+=	--without-tcl

MAKE_JOBS_SAFE=		no
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

# mach/mach.h defines panic, differently.
SUBST_CLASSES.Darwin+=	panic
SUBST_STAGE.panic=	pre-configure
SUBST_MESSAGE.panic=	Renaming the panic function
SUBST_FILES.panic=	*/*.c
SUBST_FILES.panic+=	pith/util.h
SUBST_SED.panic+=	-e 's,panic(,Panic(,g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/alpine/alpine ${DESTDIR}${PREFIX}/bin/alpine
	${INSTALL_MAN} ${WRKSRC}/doc/man1/alpine.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/alpine.1

.include "../../mk/terminfo.buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
