# $NetBSD: Makefile,v 1.7 1999/04/01 15:25:01 hwr Exp $

DISTNAME=	openldap-1.2.1
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
