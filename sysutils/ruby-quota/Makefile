# $NetBSD: Makefile,v 1.22 2012/10/23 19:51:22 asau Exp $
#

DISTNAME=	ruby-quota-0.5.1
PKGNAME=	${RUBY_PKGPREFIX}-quota-0.5.1
PKGREVISION=	11
CATEGORIES=	sysutils ruby
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-quota/}

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/ruby-quota/
COMMENT=	Quota interface for Ruby
LICENSE=	modified-bsd

USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=		site-install
INSTALLATION_DIRS=	${RUBY_VENDORLIB} ${RUBY_DOC}/quota

DOCS=		ChangeLog README

post-install:
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/quota
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
