# $NetBSD: Makefile,v 1.3 2004/03/16 02:01:10 taca Exp $

DISTNAME=		vapor-0.7.0
PKGNAME=		${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=		databases ruby
MASTER_SITES=		http://rubyforge.org/download.php/7/

MAINTAINER=		rasputin@idoru.mine.nu
HOMEPAGE=		http://vapor.rubyforge.org/
COMMENT=		Ruby transparent persistence to postgresql

DEPENDS+=		ruby-DBD-postgresql>=0.0.20:../ruby-DBD-postgresql
DEPENDS+=		ruby-rexml>=2.4.0:../../textproc/ruby-rexml
DEPENDS+=		ruby-racc>=1.4.3:../../devel/ruby-racc

WRKSRC=			${WRKDIR}/vapor-0.70
USE_RUBY_SETUP= 	yes
RUBY_SETUP= 	install.rb

post-install:
	${CP} -R ${WRKSRC}/doc ${RUBY_DOCDIR}/vapor
	${LN} -s ${RUBY_DOCDIR}/vapor/examples ${RUBY_EXAMPLESDIR}/vapor

.include "../../databases/postgresql-lib/buildlink2.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
