# $NetBSD: Makefile,v 1.22 2001/12/30 16:26:28 taca Exp $
# FreeBSD: ports/lang/ruby/Makefile,v 1.40 2001/01/18 19:53:38 knu Exp

DISTNAME=	ruby-${RUBY_VERSION}
CATEGORIES=	lang
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/en/
COMMENT=	Ruby, object-oriented interpreted scripting language

DEPENDS+=	${RUBY_PKGNAMEPREFIX}base>=${RUBY_VERSION}:../../lang/${RUBY_PKGNAMEPREFIX}base
DEPENDS+=	${RUBY_PKGNAMEPREFIX}gdbm>=${RUBY_VERSION}:../../databases/ruby-gdbm
DEPENDS+=	${RUBY_PKGNAMEPREFIX}digest>=${RUBY_VERSION}:../../security/ruby-digest
DEPENDS+=	${RUBY_PKGNAMEPREFIX}readline>=${RUBY_VERSION}:../../devel/${RUBY_PKGNAMEPREFIX}readline
DEPENDS+=	${RUBY_PKGNAMEPREFIX}tcltklib>=${RUBY_VERSION}:../../x11/ruby-tcltklib
DEPENDS+=	${RUBY_PKGNAMEPREFIX}tk>=${RUBY_VERSION}:../../x11/${RUBY_PKGNAMEPREFIX}tk

NO_CHECKSUM=	# defined
NO_PATCH=	# defined
NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:
	@${ECHO_MSG} This is only a meta package.

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
