# $NetBSD: Makefile,v 1.11 2006/08/31 08:42:41 rillig Exp $

DISTNAME=	ruby-gsl-0.2.0
PKGNAME=	${RUBY_PKGPREFIX}-gsl-0.2.0
PKGREVISION=	4
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ruby-gsl/}

MAINTAINER=	dmcmahill@NetBSD.org
HOMEPAGE=	http://ruby-gsl.sourceforge.net/
COMMENT=	Wrapper of the GNU Scientific Library (GSL) for Ruby

CONFIGURE_DIRS=		ext
RUBY_EXTCONF_SUBDIRS=	${CONFIGURE_DIRS}
RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=		site-install
DOCS=			AUTHORS HISTORY HOWTO IMPLEMENTED README THANKS \
			TODO doc.rd
REPLACE_RUBY_DIRS=	${WRKSRC}/samples

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/gsl
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${RUBY_DOCDIR}/gsl
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gsl
	${INSTALL_DATA} ${WRKSRC}/samples/*.rb ${RUBY_EXAMPLESDIR}/gsl

.include "../../lang/ruby/modules.mk"
.include "../../math/gsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
