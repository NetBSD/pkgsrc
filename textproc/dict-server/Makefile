# $NetBSD: Makefile,v 1.1.1.1 1999/07/28 16:17:19 tron Exp $

DISTNAME=       dictd-1.4.9
PKGNAME=	dict-server-1.4.9
CATEGORIES=	textproc
MASTER_SITES=   ftp://ftp.cs.unc.edu/pub/users/faith/dict/ \
		ftp://ftp.cs.unc.edu/pub/users/faith/dict/pre/ \
		ftp://ftp.dict.org/pub/dict/ \
		ftp://ftp.dict.org/pub/dict/pre/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		dict-gazetteer-1.2-pre.tar.gz \
		dict-misc-1.5-pre.tar.gz \
		dict-web1913-1.4-pre.tar.gz \
		dict-wn-1.5-pre.tar.gz

MAINTAINER=	mike@ethmoid.org
HOMEPAGE=	http://www.dict.org/

USE_GMAKE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-etcdir=${PREFIX}/etc

ALL_TARGET=	dictd dictzip
INSTALL_TARGET=	install.dictd install.dictzip

LEXICONS=	easton.dict.dz \
		easton.index \
		elements.dict.dz \
		elements.index \
		foldoc.dict.dz \
		foldoc.index \
		gazetteer.dict.dz \
		gazetteer.index \
		hitchcock.dict.dz \
		hitchcock.index \
		jargon.dict.dz \
		jargon.index \
		web1913.dict.dz \
		web1913.index \
		wn.dict.dz \
		wn.index \
		world95.dict.dz \
		world95.index

post-install:
	${SED} "s#/usr/lib/dict#${PREFIX}/share/dictd#" \
		${WRKSRC}/dictd.conf >${PREFIX}/etc/dictd.conf
	${MKDIR} ${PREFIX}/share/dictd
.for FILE in ${LEXICONS}
		${INSTALL_DATA} ${WRKDIR}/${FILE} ${PREFIX}/share/dictd
.endfor

.include "../../mk/bsd.pkg.mk"
