# $NetBSD: Makefile,v 1.2 2001/12/30 16:23:59 taca Exp $
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
USE_BUILDLINK_ONLY=	# defined

.include "../../mk/bsd.prefs.mk"
.include "../../devel/readline/buildlink.mk"

EXTRACT_ELEMENTS=	${RUBY_DISTNAME}/ext/readline
USE_RUBY_EXTCONF=	yes
RUBY_DOCS=		README README.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/readline
.for file in ${RUBY_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${RUBY_DOCDIR}/readline
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
