# $NetBSD: Makefile,v 1.10 2005/03/06 17:19:07 taca Exp $
# FreeBSD: ports/net/ruby-drb/Makefile,v 1.8 2001/01/18 16:57:25 knu Exp

DISTNAME=	drb-2.0.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net ruby
MASTER_SITES=	http://www2a.biglobe.ne.jp/~seki/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www2a.biglobe.ne.jp/~seki/ruby/
COMMENT=	Distributed Ruby

RUBY_VERSION=		${RUBY16_VERSION}
USE_BUILDLINK3=		yes
USE_RUBY_INSTALL=	yes
REPLACE_RUBY_DIRS=	${WRKSRC}/sample
DOCS=			acl-ref.rd acl-ref.rd.ja acl.rd acl.rd.ja \
			changelog.rd drb-ref.rd drb-ref.rd.ja mutexm.rd.ja \
			security.rd security.rd.ja tuplespace-ref.rd.ja

do-build:
.for f in ${DOCS}
	@cd ${WRKSRC}/doc; ${RUBY_RD} ${f} > ${f:S/.rd/.html/}
.endfor

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/drb
	${INSTALL_DATA} ${WRKSRC}/doc/* ${RUBY_DOCDIR}/drb
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/drb
	${INSTALL_DATA} ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/drb

.include "../../lang/ruby/modules.mk"
.include "../../textproc/ruby-rdtool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
