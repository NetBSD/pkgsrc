# $NetBSD: Makefile,v 1.3 1999/01/27 13:04:26 hwr Exp $

DISTNAME=	openldap-release
PKGNAME=	openldap-1.1.4
WRKSRC=		${WRKDIR}/ldap
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.OpenLDAP.org/

# for the moment without threads and thus without slurpd
#DEPENDS+=	../../devel/mit-pthreads

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
