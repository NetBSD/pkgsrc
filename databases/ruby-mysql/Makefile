# $NetBSD: Makefile,v 1.41 2022/09/01 15:29:29 taca Exp $
#

DISTNAME=	ruby-mysql-3.0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/ruby-//}
CATEGORIES=	databases

MAINTAINER=	neumann@s-direktnet.de
HOMEPAGE=	https://github.com/tmtm/ruby-mysql
COMMENT=	Ruby extension for MySQL
LICENSE=	gnu-gpl-v2 OR ruby-license

USE_LANGUAGES=	# empty

.include "../../lang/ruby/gem.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
