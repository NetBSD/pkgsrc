# $NetBSD: Makefile,v 1.18 2023/10/24 22:10:55 wiz Exp $
#

DISTNAME=	pam_p11-0.3.1
PKGREVISION=	2
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=OpenSC/}
GITHUB_TAG=	pam_p11
GITHUB_RELEASE=	pam_p11-0.3.1

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	https://opensc-project.org/opensc/wiki/pam_p11
COMMENT=	Smart card PAM module
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config autoconf automake autopoint
USE_TOOLS+=		msgfmt msgmerge xgettext

LDFLAGS+=		${BUILDLINK_LDADD.gettext}

BUILDLINK_TRANSFORM+=	rm:-Werror

WRKSRC=	${WRKDIR}/${DISTNAME}
pre-configure:
	cd ${WRKSRC} && autoreconf -f -i

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../security/libp11/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
