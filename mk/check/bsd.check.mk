# $NetBSD: bsd.check.mk,v 1.11 2022/01/18 01:41:09 pho Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and provides all
# variables and targets related to build and install checks.
#
# There are some predefined hooks where checks can be added:
#
# pre-configure-checks-hook
#	Is run before configuring the package.
#
# pre-build-checks-hook
#	Is run before building the package.
#
# #notyet post-install-privileged-checks-hook
#	Is run after the installation, as the user who installed
#	the package.
#
# #notyet post-install-checks-hook
#	Is run after the installation, as the user who built
#	the package.
#
# The following are the "public" targets provided this module:
#
#    check-files-pre, check-files-post, check-files
#    check-interpreter, check-shlibs, check-vulnerable, check-wrkref
#

.include "check-files.mk"
.include "check-headers.mk"
.include "check-interpreter.mk"
.include "check-perms.mk"
.include "check-pie.mk"
.include "check-portability.mk"
.include "check-relro.mk"
.include "check-shlibs.mk"
.include "check-ssp.mk"
.include "check-stripped.mk"
.include "check-vulnerable.mk"
.include "check-wrkref.mk"
.include "check-fakehome.mk"

pre-configure-checks-hook \
pre-build-checks-hook: .PHONY
	@${DO_NADA}

######################################################################
### check-clean (PRIVATE)
######################################################################
### check-clean is a helper target onto which one can hook all of the
### targets that clean up the output of "check" targets.
###
.PHONY: check-clean
check-clean:
	@${DO_NADA}
