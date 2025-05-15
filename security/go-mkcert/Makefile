# $NetBSD: Makefile,v 1.70 2025/05/15 19:29:16 schmonz Exp $

DISTNAME=		mkcert-1.4.4
PKGNAME=		${DISTNAME:S/^/go-/}
PKGREVISION=		21
CATEGORIES=		security
MASTER_SITES=		${MASTER_SITE_GITHUB:=FiloSottile/}
GITHUB_PROJECT=		mkcert
GITHUB_TAG=		v${PKGVERSION_NOREV}

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://mkcert.dev/
COMMENT=		Make locally trusted development certificates
LICENSE=		modified-bsd

DEPENDS+=		nss-[0-9]*:../../devel/nss

SUBST_CLASSES+=		certsdir
SUBST_STAGE.certsdir=	pre-configure
SUBST_FILES.certsdir=	truststore_*.go
SUBST_VARS.certsdir=	PREFIX SH SSLCERTS

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"

# Defining these way down here because if they're earlier,
# ERROR: bin/mkcert: is not a Position Independent Executable

# Buildlink just enough OpenSSL to get SSLCERTS defined
BUILDLINK_INCDIRS.openssl=	/nonexistent
BUILDLINK_LIBDIRS.openssl=	/nonexistent
BUILDLINK_DEPMETHOD.openssl=	build
.include "../../security/openssl/buildlink3.mk"

PLIST_VARS=		rehash
.if ${OPSYS} != "Darwin" && ${OPSYS} != "Linux"
PLIST.rehash=		yes
DEPENDS+=		mozilla-rootcerts-[0-9]*:../../security/mozilla-rootcerts
INSTALLATION_DIRS+=	libexec
post-patch:
	cd ${WRKSRC} && cp truststore_linux.go truststore_unix.go
post-install:
	${ECHO} '#!${SH} -e' > ${DESTDIR}${PREFIX}/libexec/rehash-mozilla-rootcerts
	${ECHO} 'cd "$$1" && ${PREFIX}/sbin/mozilla-rootcerts rehash' >> ${DESTDIR}${PREFIX}/libexec/rehash-mozilla-rootcerts
	chmod +x ${DESTDIR}${PREFIX}/libexec/rehash-mozilla-rootcerts
.endif

.include "../../mk/bsd.pkg.mk"
