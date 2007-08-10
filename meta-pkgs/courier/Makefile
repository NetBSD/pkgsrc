# $NetBSD: Makefile,v 1.1.1.1 2007/08/10 17:58:22 jlam Exp $

DISTNAME=	courier-${COURIER_VERSION}
CATEGORIES=	meta-pkgs mail
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	jlam@pkgsrc.org
HOMEPAGE=	http://www.courier-mta.org/
COMMENT=	Meta-package for the Courier mail server suite

# COURIER_VERSION should match the variable of the same name found in
# pkgsrc/mail/courier-mta/Makefile.common.
#
COURIER_VERSION=	0.56.0

# The following packages are built from the same Courier sources and
# should match in version number:
#
#	net/couriertcpd, mail/courier-maildir, mail/courier-mta
#
DEPENDS+=	couriertcpd>=${COURIER_VERSION}:../../net/couriertcpd
DEPENDS+=	courier-maildir>=${COURIER_VERSION}:../../mail/courier-maildir
DEPENDS+=	courier-mta>=${COURIER_VERSION}:../../mail/courier-mta

# The following packages must be from the same lineage as the version
# of Courier:
#
#	mail/maildrop, mail/courier-imap, mail/sqwebmail
#
DEPENDS+=	maildrop>=2.0.4:../../mail/maildrop
DEPENDS+=	courier-imap>=4.1.3:../../mail/courier-imap
DEPENDS+=	sqwebmail>=5.1.6:../../mail/sqwebmail

EXTRACT_ONLY=	# empty
NO_CHECKSUM=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

do-install:	# empty

.include "../../mk/bsd.pkg.mk"
