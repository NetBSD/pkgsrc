# $NetBSD: Makefile,v 1.12 2020/03/20 11:58:18 nia Exp $
#

DISTNAME=	pam_tacplus-1.3.6
PKGNAME=	${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tacplus/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://tacplus.sourceforge.net/
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
