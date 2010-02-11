# $NetBSD: Makefile,v 1.1.1.1 2010/02/11 13:13:24 joerg Exp $
#

DISTNAME=	cx_Oracle-5.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=cx-oracle/}

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://cx-oracle.sourceforge.net
COMMENT=	Oracle binding for Python

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes

.include "../../mk/bsd.prefs.mk"

.if !defined(ORACLE_HOME)
PKG_FAIL_REASON+=	"You must set ORACLE_HOME to the location of your Oracle installation"
.elif !exists(${ORACLE_HOME})
PKG_FAIL_REASON+=	"The location of ORACLE_HOME does not exist"
.endif

BUILDLINK_PASSTHRU_DIRS+=	${ORACLE_HOME}
BUILDLINK_PASSTHRU_RPATHDIRS+=	${ORACLE_HOME}
LDFLAGS+=	-Wl,-rpath,${ORACLE_HOME}/lib

ALL_ENV+=	ORACLE_HOME=${ORACLE_HOME:Q}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
