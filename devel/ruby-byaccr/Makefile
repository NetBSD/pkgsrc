# $NetBSD: Makefile,v 1.3 2003/08/30 07:29:53 taca Exp $
# FreeBSD: ports/devel/ruby-byaccr/Makefile,v 1.2 2000/11/03 15:49:06 knu Exp

DISTNAME=	byaccr-0.1
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.idaemons.org/pub/distfiles/ruby/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Parser generator for ruby based on 'Berkeley Yacc/Yacc for Java'

DIST_SUBDIR=	ruby
USE_RUBY=	yes

EXAMPLES=	Makefile cal.y calfunc.rb main.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/byaccr
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/sample/${f} ${RUBY_EXAMPLESDIR}/byaccr
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
