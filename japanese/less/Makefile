# $NetBSD: Makefile,v 1.1.1.1 1998/10/28 18:12:10 garbled Exp $
# FreeBSD Id: Makefile,v 1.13 1998/07/17 20:36:13 steve Exp
#

DISTNAME=       less-332
PKGNAME=        ja-less-332
CATEGORIES=     japanese
MASTER_SITES=   ${MASTER_SITE_GNU}

PATCH_SITES=    ftp://ftp.big.or.jp/pub/usr2/jam/less/
PATCHFILES=     less-332-iso242.patch.gz \
		less-332-iso242-243.patch.gz \
		less-332-iso243-244.patch.gz \
		less-332-iso244-245.patch.gz \
		less-332-iso245-247.patch.gz \
		less-332-iso247-248.patch.gz
PATCH_DIST_STRIP=   -p1

MAINTAINER=     komine@cc.meisei-u.ac.jp
HOMEPAGE=       http://www.io.com/~kazushi/less/

GNU_CONFIGURE=  yes

.include "../../mk/bsd.pkg.mk"
