# $NetBSD: Makefile,v 1.5 2004/11/27 16:00:49 taca Exp $
# FreeBSD: ports/devel/ruby-byaccr/Makefile,v 1.2 2000/11/03 15:49:06 knu Exp

DISTNAME=	byaccr-0.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	ftp://ftp.idaemons.org/pub/distfiles/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	Parser generator for ruby based on 'Berkeley Yacc/Yacc for Java'
EXAMPLES=	Makefile cal.y calfunc.rb main.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/byaccr
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/byaccr
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
