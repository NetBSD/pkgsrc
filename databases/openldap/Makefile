# $NetBSD: Makefile,v 1.6 1999/03/28 18:27:22 hwr Exp $

DISTNAME=	openldap-1.2.0
WRKSRC=		${WRKDIR}/ldap
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.openldap.org/pub/OpenLDAP/openldap-release/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.OpenLDAP.org/

# for the moment without threads and thus without slurpd
#DEPENDS+=	../../devel/mit-pthreads

HAS_CONFIGURE=	yes
CONFIGURE_ARGS+= --prefix=${PREFIX}

.include "../../mk/bsd.pkg.mk"
