# $NetBSD: Makefile,v 1.3 2002/01/03 15:21:38 taca Exp $
# FreeBSD: ports/security/ruby-acl/Makefile,v 1.4 2000/12/26 04:13:28 knu Exp

DISTNAME=	acl-1.0.1
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	Ruby module to provide Access Control List checks

DIST_SUBDIR=	ruby
USE_RUBY_RD=	yes
RD_DOCS=	acl.rd acl.rd.ja
DOCS=		README doc/acl.rd doc/acl.html \
		README.ja doc/acl.rd.ja doc/acl.html.ja

do-build:
.for f in ${RD_DOCS}
	@cd ${WRKSRC}/doc; \
	${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor

do-install:
	@cd ${WRKSRC}; \
	${RUBY} install.rb
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/acl
	${INSTALL_DATA} ${WRKSRC}/acltest.rb ${RUBY_EXAMPLESDIR}/acl
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/acl
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/acl
.endfor

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
