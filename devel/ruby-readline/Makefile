# $NetBSD: Makefile,v 1.3 2002/10/25 18:33:29 wiz Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGNAMEPREFIX}readline-${RUBY_VERSION}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@netbsd.org
HOMEPAGE=		http://www.ruby-lang.org/en/
COMMENT=		Ruby extension to readline library

DIST_SUBDIR=		ruby
WRKSRC=			${RUBY_WRKSRC}/ext/readline
USE_GNU_READLINE=	# uses rl_event_hook interface to GNU readline
USE_BUILDLINK2=		# defined

EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/readline
USE_RUBY_EXTCONF=	yes
RUBY_DOCS=		README README.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/readline
.for file in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${RUBY_DOCDIR}/readline
.endfor

.include "../../devel/readline/buildlink2.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
