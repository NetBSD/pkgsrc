# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 14:25:06 taca Exp $
# FreeBSD: ports/net/ruby-drb/Makefile,v 1.8 2001/01/18 16:57:25 knu Exp

DISTNAME=	drb-1.3.2
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/ \
		${MASTER_SITE_RUBY:S/$/contrib\//g}

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	Distributed Ruby

DEPENDS+=	${RUBY_PKGNAMEPREFIX}acl>=1.0.1:../../security/ruby-acl
DEPENDS+=	${RUBY_PKGNAMEPREFIX}mutexm>=1.0.1:../../devel/ruby-mutexm

DIST_SUBDIR=	ruby
USE_RUBY=	yes
USE_RUBY_RD=	yes

DOCS_EN=	drb-ref.rd
DOCS_JA=	tuplespace-ref.rd.ja drb-ref.rd.ja

pre-configure:
	${RM} -f ${WRKSRC}/doc/acl*
	${RM} -f ${WRKSRC}/lib/acl.rb
	${RM} -f ${WRKSRC}/lib/mutexm.rb
	${RM} -f ${WRKSRC}/runit/acl-test.rb

do-build:
.for f in ${DOCS_EN}
	@cd ${WRKSRC}/doc; ${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor
.for f in ${DOCS_JA}
	@cd ${WRKSRC}/doc; ${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/drb/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${WRKSRC}/doc/${f:S/.rd/.html/} \
		${RUBY_DOCDIR}/drb
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/drb-ref.rd ${RUBY_DOCDIR}/drb
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${WRKSRC}/doc/${f:S/.rd/.html/} \
		${RUBY_DOCDIR}/drb/ja
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/drb-ref.rd.ja ${RUBY_DOCDIR}/drb/ja
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/drb/runit
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/drb
	${INSTALL_DATA} ${WRKSRC}/runit/* ${RUBY_EXAMPLESDIR}/drb/runit

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
