# $NetBSD: apache.mk,v 1.13 2006/07/10 17:11:32 wiz Exp $
#
# This Makefile fragment handles Apache dependencies and make variables,
# and is meant to be included by packages that require Apache either at
# build-time or at run-time.  apache.mk will:
#
#	* set PKG_APACHE to the name of the apache web server used
#
#	* add a full dependency on the apache server
#
#	* optionally add a full dependency on apr
#
# The available user variables are:
#
# PKG_APACHE_DEFAULT is a user-settable variable whose value is the default
#	apache server to use.  Possible values are apache13 and apache2.
#   If there is already a version of apache installed this will have no
#   effect.
#
# The available makefile variables are:
#
# PKG_APACHE_ACCEPTED is a package-settable list of servers that may be used as
#	possible dependencies for the package.  Possible values are the same as
#   for PKG_APACHE_DEFAULT.
#
# USE_APR is used to note that the package requires the Apache Portable
#   runtime to build and execute.  This is only takes effect if apache2
#   is chosen (by this file) as the web server to use.  This adds a full
#   dependency on apr.
#

.if !defined(APACHE_MK)
APACHE_MK=	# defined

.include "../../mk/apachever.mk"

# Add a runtime dependency on the apache server.
# This may or may not create an actual dependency depending on
# what the apache buildlink3.mk file does.
#
.if defined(_APACHE_PKGSRCDIR)
.  include "${_APACHE_BL_SRCDIR}/buildlink3.mk"
.endif

# If we are building apache modules, then we might need a build-time
# dependency on apr, and the apache sources?
#
.if ${_PKG_APACHE} == "apache2"
.  if defined(USE_APR) && !empty(USE_APR:M[yY][eE][sS])
.    include "../../devel/apr/buildlink3.mk"
.  endif
.endif

.endif	# APACHE_MK
