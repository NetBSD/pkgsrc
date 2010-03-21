# $NetBSD: Makefile,v 1.15 2010/03/21 16:29:41 wiz Exp $

DISTNAME=	courier-${COURIER_VERSION}
CATEGORIES=	meta-pkgs mail
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.courier-mta.org/
COMMENT=	Meta-package for the Courier mail server suite

META_PACKAGE=	yes

# COURIER_VERSION should match the variable of the same name found in
# pkgsrc/mail/courier-mta/Makefile.common.
#
COURIER_VERSION=	0.58.0

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
DEPENDS+=	maildrop>=2.0.4nb3:../../mail/maildrop
DEPENDS+=	courier-imap>=4.3.0:../../mail/courier-imap
DEPENDS+=	sqwebmail>=5.2.0nb2:../../mail/sqwebmail

# We tack on courier-analog because its version is somewhat tied to the
# log format of the current Courier release.
#
DEPENDS+=	courier-analog>=0.15:../../mail/courier-analog

.include "../../mk/bsd.pkg.mk"
