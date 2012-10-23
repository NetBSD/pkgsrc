# $NetBSD: Makefile,v 1.7 2012/10/23 18:16:49 asau Exp $
#

DISTNAME=	pam_tacplus-1.3.6
PKGNAME=        ${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tacplus/}

MAINTAINER=	pettai@NetBSD.org
HOMEPAGE=	http://tacplus.sourceforge.net/
COMMENT=	TACACS+ client library and PAM module
LICENSE=	gnu-gpl-v2

EGDIR=		${PREFIX}/share/examples/pam_tacplus

GNU_CONFIGURE=yes

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	post-patch
SUBST_FILES.egdir=	Makefile.in
SUBST_SED.egdir=	-e "s,@EGDIR@,${EGDIR},"

.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
