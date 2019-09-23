# $NetBSD: Makefile,v 1.4 2019/09/23 00:22:03 mef Exp $

DISTNAME=	I18N_UnicodeNormalizer-1.0.0
PKGREVISION=	1
CATEGORIES+=	converters

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	PHP classes to provide Unicode Normalization

LICENSE=	2-clause-bsd

DEPENDS+=	${PHP_PKG_PREFIX}-mbstring>=5.0:../../converters/php-mbstring

.include "../../lang/php/pear.mk"

# fno/I18N_UnicodeNormalizer-1.0.0.tgz:   last modified: Sat Aug  4 14:58:59 2007, from Unix, original size modulo 2^32 3039599536
# new/I18N_UnicodeNormalizer-1.0.0.tgz:   last modified: Sat Aug  4 14:58:59 2007, from Unix, original size modulo 2^32 14620160
# old/I18N_UnicodeNormalizer-1.0.0.tgz:    gzip compressed data, from NTFS filesystem (NT), original size modulo 2^32 14620160
# overwrite default, tar ball created by different OS
DIST_SUBDIR=	pear/I18N_UnicodeNormalizer-dir

.include "../../mk/bsd.pkg.mk"
