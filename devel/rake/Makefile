# $NetBSD: Makefile,v 1.4 2006/08/07 16:11:32 taca Exp $

DISTNAME=	rake-0.7.1
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/9499/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rake.rubyforge.org/
COMMENT=	Ruby Make

NO_BUILD=		yes
USE_RUBY_INSTALL=	yes
USE_TOOLS+=		gunzip
DOCDIR=			${RUBY_DOCDIR}/rake
EXAMPLESDIR=		${RUBY_EXAMPLESDIR}/rake
DOCS=			CHANGES README TODO doc/glossary.rdoc \
			doc/jamis.rb doc/proto_rake.rdoc \
			doc/rakefile.rdoc doc/rational.rdoc
EXAMPLES=		Rakefile1 Rakefile2 a.c b.c main.c

pre-configure:
	${MV} ${WRKSRC}/bin/rake ${WRKSRC}/bin/rake.orig
	${ECHO} "#!${RUBY}" > ${WRKSRC}/bin/rake
	${CAT} ${WRKSRC}/bin/rake.orig >> ${WRKSRC}/bin/rake
	${RM} ${WRKSRC}/bin/rake.orig

post-install:
	if [ ! -f ${WRKSRC}/doc/rake.1 ]; then \
		${GUNZIP_CMD} ${WRKSRC}/doc/rake.1.gz; \
	fi
	${INSTALL_MAN} ${WRKSRC}/doc/rake.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${DOCDIR}/release_notes
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCDIR}
.endfor
	for f in ${WRKSRC}/doc/release_notes/*; do \
		${INSTALL_DATA} $$f ${DOCDIR}/release_notes; \
	done
	${INSTALL_DATA_DIR} ${EXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/example/${f} ${EXAMPLESDIR}
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
