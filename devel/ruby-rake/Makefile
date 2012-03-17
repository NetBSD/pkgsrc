# $NetBSD: Makefile,v 1.1.1.1 2012/03/17 13:51:36 taca Exp $

DISTNAME=	rake-0.8.7
PKGREVISION=	2
CATEGORIES=	devel

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/rake/
COMMENT=	Ruby Make
LICENSE=	mit

USE_TOOLS+=	gzip

OVERRIDE_GEMSPEC+= :executables rake=rake${RUBY_VER} \
		:files bin/rake=bin/rake${RUBY_VER} doc/rake.1.gz=doc/rake.1 \
		test/data/unittest/subdir=

FIX_PERM=	doc/release_notes/rake-0.7.3.rdoc \
		lib/rake/ruby182_test_unit_fix.rb

CONFLICTS+=	 rake-[0-9]*

# rake is bundled Ruby 1.9
RUBY_VERSION_SUPPORTED= 18
INSTALLATION_DIRS=	${PKGMANDIR}/man1

pre-configure:
	cd ${WRKSRC}/doc && gzip -d rake.1.gz
	cd ${WRKSRC}; ${CHMOD} -x ${FIX_PERM}
	${MV} ${WRKSRC}/bin/rake ${WRKSRC}/bin/rake${RUBY_VER}

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/rake.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/rake${RUBY_VER}.1

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
