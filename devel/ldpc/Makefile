# $NetBSD: Makefile,v 1.3 2012/10/31 11:17:09 asau Exp $

DISTNAME=	LDPC-2006-02-08
PKGNAME=	ldpc-20060208
CATEGORIES=	devel
PKGREVISION=	1
MASTER_SITES=	http://www.cs.utoronto.ca/~radford/ftp/LDPC-2006-02-08/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.cs.utoronto.ca/~radford/ftp/LDPC-2006-02-08/index.html
COMMENT=	Low Density Parity Check Codes
LICENSE=	ldpc-license

BUILD_TARGET=		progs

AUTO_MKDIRS=		yes

LDPCPROGS= make-pchk alist-to-pchk pchk-to-alist make-ldpc print-pchk make-gen
LDPCPROGS+= print-gen rand-src encode transmit decode extract verify

LDPCDOCS= channel.html decode-detail.html decoding.html dep-H.html
LDPCDOCS+= encoding.html examples.html index.html install.html mod2convert.html
LDPCDOCS+= mod2dense.html mod2sparse.html modify.html modules.html pchk.html
LDPCDOCS+= progs.html rand.html refs.html release.html sparse-LU.html
LDPCDOCS+= support.html

LDPCRANDFILE=	randfile

do-install:
	for p in ${LDPCPROGS}; do					\
		${INSTALL_PROGRAM} ${WRKSRC}/$$p ${DESTDIR}${PREFIX}/bin; \
	done
	for d in ${LDPCDOCS} ${LDPCRANDFILE}; do			\
		${INSTALL_DATA} ${WRKSRC}/$$d ${DESTDIR}${PREFIX}/share/ldpc; \
	done

.include "../../mk/bsd.pkg.mk"
