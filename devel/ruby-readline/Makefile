# $NetBSD: Makefile,v 1.11 2004/04/27 03:09:58 snj Exp $
#

DISTNAME=		${RUBY_DISTNAME}
PKGNAME=		${RUBY_PKGNAMEPREFIX}readline-${RUBY_VERSION}
PKGREVISION=		3
CATEGORIES=		devel ruby
MASTER_SITES=		${MASTER_SITE_RUBY}

MAINTAINER=		taca@NetBSD.org
HOMEPAGE=		http://www.ruby-lang.org/en/
COMMENT=		Ruby extension to readline library

WRKSRC=			${RUBY_WRKSRC}/ext/readline
DIST_SUBDIR=		ruby
USE_GNU_READLINE=	# uses rl_event_hook interface to GNU readline
USE_BUILDLINK3=		yes

EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/readline
USE_RUBY_EXTCONF=	yes
RUBY_DOCS=		README README.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/readline
.for file in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${RUBY_DOCDIR}/readline
.endfor

.include "../../devel/readline/buildlink3.mk"
.include "../../lang/ruby-base/Makefile.common"
.include "../../lang/ruby-base/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
