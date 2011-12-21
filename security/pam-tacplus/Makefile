# $NetBSD: Makefile,v 1.4 2011/12/21 12:30:21 wiz Exp $
#

DISTNAME=	pam_tacplus-1.3.5
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

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		egdir
SUBST_STAGE.egdir=	post-patch
SUBST_FILES.egdir=	Makefile.in
SUBST_SED.egdir=	-e "s,@EGDIR@,${EGDIR},"

.include "../../mk/bsd.pkg.mk"
