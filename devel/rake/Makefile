# $NetBSD: Makefile,v 1.8 2008/03/12 03:21:05 jlam Exp $

DISTNAME=	rake-0.8.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/29752/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rake.rubyforge.org/
COMMENT=	Ruby Make

PKG_DESTDIR_SUPPORT=	user-destdir

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes
USE_TOOLS+=		gunzip
DOCDIR=			${RUBY_DOCDIR}/rake
EXAMPLESDIR=		${RUBY_EXAMPLESDIR}/rake
DOCS=			CHANGES README TODO doc/glossary.rdoc \
			doc/jamis.rb doc/proto_rake.rdoc \
			doc/rakefile.rdoc doc/rational.rdoc
EXAMPLES=		Rakefile1 Rakefile2 a.c b.c main.c

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doc/rake.1
SUBST_SED.paths=	-e 's,/usr/share/doc/,${RUBY_DOCDIR}/,g'

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../lang/ruby/modules.mk"

post-extract:
	if [ ! -f ${WRKSRC}/doc/rake.1 ]; then \
		${GUNZIP_CMD} ${WRKSRC}/doc/rake.1.gz; \
	fi

post-install:
	${INSTALL_MAN} ${WRKSRC}/doc/rake.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DESTDIR}${DOCDIR}/release_notes
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor
	for f in ${WRKSRC}/doc/release_notes/*; do \
		${INSTALL_DATA} $$f ${DESTDIR}${DOCDIR}/release_notes; \
	done
	${INSTALL_DATA_DIR} ${DESTDIR}${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/example/${f} ${DESTDIR}${EXAMPLESDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
