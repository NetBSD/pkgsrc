# $NetBSD: Makefile,v 1.1.1.1 2005/03/29 14:16:35 minskim Exp $

DISTNAME=	imlib2-ruby-${VER}
PKGNAME=	${RUBY_PKGPREFIX}-imlib2-${VER}
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.pablotron.org/download/

MAINTAINER=	obata@lins.jp
HOMEPAGE=	http://www.pablotron.org/software/imlib2-ruby/
COMMENT=	Imlib2 bindings for Ruby

VER=		0.5.0

PLIST_SRC=		${WRKDIR}/PLIST
REPLACE_RUBY_DIRS=	${WRKSRC}/examples
RUBY_HAS_ARCHLIB=	yes
RUBY_REQD=		1.8.0
USE_RUBY_EXTCONF=	yes
USE_X11= 		yes

INSTALL_TARGET=	site-install

BUILDLINK_DEPENDS.imlib2+=      imlib2>=1.2.0nb2

.include "../../graphics/imlib2/buildlink3.mk"
.include "../../lang/ruby/modules.mk"

DOCS=		AUTHORS COPYING ChangeLog README TODO

post-install:
	cd ${WRKSRC}/examples && ${PAX} -rw -pp -pm . ${RUBY_EXAMPLESDIR}/imlib2
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/imlib2
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/imlib2
.endfor
	cd ${WRKSRC}/doc && ${PAX} -rw -pp -pm . ${RUBY_DOCDIR}/imlib2/api
	@${CP} ${PKGDIR}/PLIST ${PLIST_SRC}
	cd ${RUBY_DOCDIR} && \
	${FIND} imlib2 \! -type d -print | ${SORT} | \
	while read FN; do \
	  ${ECHO} "\$${RUBY_DOCDIR}/$${FN}"; \
	done >> ${PLIST_SRC} && \
	${FIND} -d imlib2 -type d -print | \
	while read DIR; do \
	  ${ECHO} "@dirrm \$${RUBY_DOCDIR}/$${DIR}"; \
	done >> ${PLIST_SRC}

.include "../../mk/bsd.pkg.mk"
