# $NetBSD: Makefile,v 1.4 2002/09/04 12:59:13 taca Exp $
# FreeBSD: ports/net/ruby-drb/Makefile,v 1.8 2001/01/18 16:57:25 knu Exp

DISTNAME=	drb-1.3.7
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	net
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	Distributed Ruby

DEPENDS+=	${RUBY_PKGNAMEPREFIX}acl>=1.0.1:../../security/ruby-acl
DEPENDS+=	${RUBY_PKGNAMEPREFIX}mutexm>=1.0.1:../../devel/ruby-mutexm

DIST_SUBDIR=	ruby
RUBY_REQD=	1.6.5
USE_RUBY_RD=	# defined

DOCS=		drb-ref.rd drb-ref.rd.ja tuplespace-ref.rd.ja

pre-configure:
	${RM} -f ${WRKSRC}/doc/acl*
	${RM} -f ${WRKSRC}/lib/acl.rb
	${RM} -f ${WRKSRC}/lib/mutexm.rb
	${RM} -f ${WRKSRC}/runit/acl-test.rb
	${RM} -f ${WRKSRC}/runit/mutexm_unit.rb

do-build:
.for f in ${DOCS}
	@cd ${WRKSRC}/doc; ${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/drb
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${WRKSRC}/doc/${f:S/.rd/.html/} \
		${RUBY_DOCDIR}/drb
.endfor
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/drb
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/drb

.include "../../textproc/ruby-rdtool/Makefile.common"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
