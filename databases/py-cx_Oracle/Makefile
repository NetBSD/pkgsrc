# $NetBSD: Makefile,v 1.8 2022/11/09 13:14:07 joerg Exp $
#

DISTNAME=	cx_Oracle-5.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cx-oracle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://cx-oracle.sourceforge.net/
COMMENT=	Oracle binding for Python

PYDISTUTILSPKG=	yes

.include "../../mk/bsd.prefs.mk"

.if !defined(ORACLE_HOME)
PKG_FAIL_REASON+=	"You must set ORACLE_HOME to the location of your Oracle installation"
.elif !exists(${ORACLE_HOME})
PKG_FAIL_REASON+=	"The location of ORACLE_HOME does not exist"
.endif

BUILDLINK_PASSTHRU_DIRS+=	${ORACLE_HOME}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${ORACLE_HOME}
LDFLAGS+=			-Wl,-rpath,${ORACLE_HOME}/lib

ALL_ENV+=	ORACLE_HOME=${ORACLE_HOME:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
