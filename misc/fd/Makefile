# $NetBSD: Makefile,v 1.5 1998/06/22 12:52:31 agc Exp $
# FreeBSD Id: Makefile,v 1.5 1997/01/06 06:38:33 max Exp
#

DISTNAME=	FD-1.01
PKGNAME=	fd-1.01h
CATEGORIES=	misc
# The original distribution (NetNews articles) can be found at following site.
#  site= ftp://skylark.ics.es.osaka-u.ac.jp/pub/FDclone/
#  files= FD-1.01 FD-1.01g FD-1.01h
# Here ,we use already decoded archive for convenience.
MASTER_SITES=	ftp://ftp.hipecs.hokudai.ac.jp/pub/unix/FD/ \
		ftp://ftp.cc.saga-u.ac.jp/pub/fj.sources/FD/

PATCH_SITES=	${MASTER_SITES}
PATCHFILES=	FD-1.01g.patch.gz FD-1.01h.patch.gz

MAINTAINER=	nobu@psrc.isac.co.jp

ALL_TARGET=	goal
INSTALL_TARGET=	install

do-configure:
	cd ${WRKSRC} ; make config

post-install:
	@strip ${PREFIX}/bin/fd
	cd ${WRKSRC} ; [ -f .fdrc ] && ${CP} .fdrc ${PREFIX}/etc/fdrc

.include "../../mk/bsd.pkg.mk"
