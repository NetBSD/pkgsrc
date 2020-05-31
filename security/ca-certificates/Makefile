# $NetBSD: Makefile,v 1.1 2020/05/31 15:53:44 kim Exp $

PKGNAME=	ca-certificates-20190110
DISTNAME=	${PKGNAME:C/-([^-]*)$/_\1/}
CATEGORIES=	security
MASTER_SITES=	http://deb.debian.org/debian/pool/main/c/ca-certificates/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://packages.debian.org/source/sid/ca-certificates
COMMENT=	Root CA certificates from the Mozilla Project
LICENSE=	gnu-gpl-v2 AND mpl-2.0

NO_CONFIGURE=		yes
PYTHON_FOR_BUILD_ONLY=	yes

USE_TOOLS=	awk:run echo:run expr:run ln:run ls:run openssl:run rm:run mkdir:run

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
DATADIR=	${PREFIX}/share/${PKGBASE}
EGDIR=		${PREFIX}/share/examples/${PKGBASE}

# Set paths depending on whether we depend on builtin or pkgsrc
# openssl.  \todo Arguably, we should consider installing into both
# builtin and pkgsrc, if both exist, but this requires much more
# thought.
CHECK_BUILTIN.openssl=	yes
.include "../../security/openssl/builtin.mk"
CHECK_BUILTIN.openssl=	no
.if !empty(USE_BUILTIN.openssl:M[yY][eE][sS])
SSLDIR=		/etc/openssl
.else
SSLDIR=		${PKG_SYSCONFDIR}/openssl
.endif

SUBST_CLASSES=		conf paths
SUBST_MESSAGE.conf=	Adjusting configuration file.
SUBST_STAGE.conf=	post-build
SUBST_FILES.conf=	ca-certificates.conf
SUBST_SED.conf=		-e 's,^share/ca-certificates/,,'
SUBST_MESSAGE.paths=	Replacing hard-coded paths.
SUBST_STAGE.paths=	post-build
SUBST_FILES.paths=	Makefile sbin/Makefile
SUBST_FILES.paths+=	ca-certificates.conf
SUBST_FILES.paths+=	sbin/update-ca-certificates sbin/update-ca-certificates.8
SUBST_SED.paths=	-e 's,/usr/sbin,${PREFIX}/sbin,g'
SUBST_SED.paths+=	-e 's,/etc/ca-certificates.conf,${PKG_SYSCONFDIR}/ca-certificates.conf,g'
SUBST_SED.paths+=	-e 's,/etc/ssl,${SSLDIR},g'
SUBST_SED.paths+=	-e 's,/usr/share/ca-certificates,${DATADIR},g'

INSTALLATION_DIRS=	sbin ${DATADIR} ${EGDIR} share/man/man8

CONF_FILES=		${EGDIR}/ca-certificates.conf \
			${PKG_SYSCONFDIR}/ca-certificates.conf

pre-build:
	@${CP} ${FILESDIR}/ca-certificates.conf ${WRKSRC}/
	@${GREP} '^share/ca-certificates/' ${FILESDIR}/../PLIST \
	    >> ${WRKSRC}/ca-certificates.conf

post-install:
	${INSTALL_MAN} ${WRKSRC}/sbin/update-ca-certificates.8 \
	    ${DESTDIR}${PREFIX}/share/man/man8/update-ca-certificates.8
	${INSTALL_DATA} ${WRKSRC}/ca-certificates.conf \
	    ${DESTDIR}${EGDIR}/ca-certificates.conf

.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
