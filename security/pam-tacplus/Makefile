# $NetBSD: Makefile,v 1.14 2025/11/17 11:01:23 wiz Exp $

DISTNAME=	pam_tacplus-1.3.6
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tacplus/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://tacplus.sourceforge.net/
COMMENT=	TACACS+ client library and PAM module
LICENSE=	gnu-gpl-v2

EGDIR=		${PREFIX}/share/examples/pam_tacplus

GNU_CONFIGURE=	yes

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	pre-configure
SUBST_FILES.egdir=	Makefile.in
SUBST_VARS.egdir=	EGDIR

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
