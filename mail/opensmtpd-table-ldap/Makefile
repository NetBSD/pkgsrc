# $NetBSD: Makefile,v 1.1 2024/12/04 22:54:16 vins Exp $

DISTNAME=	table-ldap-1.0
PKGNAME=	${DISTNAME:S|^|opensmtpd-|}
CATEGORIES=	mail databases
MASTER_SITES=	${MASTER_SITE_GITHUB:=opensmtpd/}
GITHUB_PROJECT=	table-ldap
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://github.com/opensmtpd/table-ldap
COMMENT=	OpenSMTPD LDAP table add-on
LICENSE=	isc

CONFLICTS+=	opensmtpd-extras-[0-9]*
DEPENDS+=	opensmtpd>=7.6.0:../../mail/opensmtpd

USE_TOOLS+=	autoconf automake autoreconf

GNU_CONFIGURE=	yes

SUBST_CLASSES+=		dir
SUBST_STAGE.dir=	pre-configure
SUBST_MESSAGE.dir=	Fixing smtpdir for pkgsrc.
SUBST_FILES.dir=	Makefile.am
SUBST_SED.dir+=		-e "s:libexec/smtpd:libexec/opensmtpd:g"

INSTALLATION_DIRS+=	share/examples/opensmtpd

pre-configure:
	set -e; cd ${WRKSRC} && autoreconf -fiv

post-install:
.for f in table-ldap.conf.example
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/examples/opensmtpd/${f:S/.example//}
.endfor

.include "../../databases/openldap-client/buildlink3.mk"
.include "../../security/libretls/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
