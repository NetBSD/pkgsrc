# $NetBSD: install.mk,v 1.2 2016/04/10 15:58:03 joerg Exp $
#
# _pkgformat-install-clean:
#	Removes the state files from the run of an ``install'' target.
#

_pkgformat-install-clean: .PHONY _pkgformat-clean-metadata
