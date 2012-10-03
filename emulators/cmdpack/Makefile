# $NetBSD: Makefile,v 1.3 2012/10/03 12:55:10 asau Exp $
#

DISTNAME=	cmdpack-1.03-src
PKGNAME=	${DISTNAME:S/-src//}
CATEGORIES=	emulators
MASTER_SITES=	http://www.neillcorlett.com/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.neillcorlett.com/cmdpack/
COMMENT=	Neill Corlett's command line tools for emulation
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS=	bin share/doc/cmdpack

do-build:
	cd ${WRKSRC}/src && \
	for file in bin2iso bincomp brrrip byteshuf byteswap cdpatch ecm fakecrc hax65816 id3point pecompat rels screamf subfile uips usfv vb2rip wordadd zerofill; do \
		${CC} -o $$file $$file.c; \
	done

do-install:
	cd ${WRKSRC}/src && \
	for file in bin2iso bincomp brrrip byteshuf byteswap cdpatch ecm fakecrc hax65816 id3point pecompat rels screamf subfile uips usfv vb2rip wordadd zerofill; do \
		${INSTALL_PROGRAM} $$file ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/cmdpack.txt ${DESTDIR}${PREFIX}/share/doc/cmdpack

.include "../../mk/bsd.pkg.mk"
