# $NetBSD: Makefile,v 1.2 2019/05/05 20:27:12 wiedi Exp $

DISTNAME=	RETRO${RETRO_REL}-${RETRO_SNAPSHOT}
PKGNAME=	forth-retro-${RETRO_REL}.0.${RETRO_SNAPSHOT}
CATEGORIES=	lang
MASTER_SITES=	https://forthworks.com/retro/r/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://forthworks.com/retro/
COMMENT=	Clean, elegant, and pragmatic dialect of Forth
LICENSE=	isc

RETRO_REL=	12
RETRO_SNAPSHOT=	2018.1

USE_TOOLS+=	pax

LDFLAGS.SunOS+=	-lsocket -lnsl

REPLACE_INTERPRETER+=	rre
REPLACE.rre.old=	.*rre
REPLACE.rre.new=	${PREFIX}/bin/rre
REPLACE_FILES.rre=	bin/listener

INSTALLATION_DIRS=	bin
INSTALLATION_DIRS+=	share/doc/${PKGBASE}
INSTALLATION_DIRS+=	share/doc/${PKGBASE}/literate
INSTALLATION_DIRS+=	share/${PKGBASE}
INSTALLATION_DIRS+=	share/examples/${PKGBASE}

# Reimplement build.sh
do-build:
	${RUN} cd ${WRKSRC}/tools && \
	for file in unu muri embedimage extend; do \
		${CC} ${CFLAGS} ${LDFLAGS} -lm -o $$file $$file.c; \
	done

	${RUN} cd ${WRKSRC} && \
		./tools/unu literate/Unu.md > tools/unu.c; \
		./tools/unu literate/Muri.md > tools/muri.c; \
		./tools/muri literate/Rx.md; \
		./tools/extend literate/RetroForth.md

	${RUN} ${LN} -sf ${WRKSRC}/ngaImage ${WRKSRC}/interfaces/ri/ngaImage
	${RUN} cd ${WRKSRC}/interfaces/ri/ && \
		../../tools/embedimage > image.c

	${RUN} ${LN} -sf ${WRKSRC}/ngaImage ${WRKSRC}/interfaces/ngaImage
	${RUN} cd ${WRKSRC}/interfaces/ && \
		../tools/extend rre_windows.forth; \
		../tools/embedimage > image_windows.c; \
		../tools/extend rre.forth; \
		../tools/embedimage > image.c

	${RUN} cd ${WRKSRC}/interfaces/ && \
	for file in rre repl; do \
		${CC} ${CFLAGS} ${LDFLAGS} -lm -o $$file $$file.c; \
	done

	${RUN} cd ${WRKSRC} && \
		sort -o words.tsv words.tsv

	${RUN} cd ${WRKSRC} && \
		./interfaces/rre glossary.forth export glossary > doc/Glossary.txt

do-install:
.for f in embedimage extend muri unu
	${RUN} ${INSTALL_PROGRAM} \
		${WRKSRC}/tools/${f} \
		${DESTDIR}${PREFIX}/bin/${f}
.endfor

.for f in rre repl
	${RUN} ${INSTALL_PROGRAM} \
		${WRKSRC}/interfaces/${f} \
		${DESTDIR}${PREFIX}/bin/${f}
.endfor

	${RUN} ${INSTALL_SCRIPT} \
		${WRKSRC}/bin/listener \
		${DESTDIR}${PREFIX}/bin/listener

.for f in README.md RELEASE_NOTES.md
	${RUN} ${INSTALL_DATA} \
		${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
.endfor
	${RUN} cd ${WRKSRC}/doc && \
		${PAX} -rw . ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}
	${RUN} cd ${WRKSRC}/literate && \
		${PAX} -rw . ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/literate

.for f in glossary.forth ngaImage words.tsv
	${RUN} ${INSTALL_DATA} \
		${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/${PKGBASE}
.endfor

	${RUN} cd ${WRKSRC}/example && \
		${PAX} -rw . ${DESTDIR}${PREFIX}/share/examples/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
