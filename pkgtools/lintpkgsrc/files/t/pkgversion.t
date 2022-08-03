# $NetBSD: pkgversion.t,v 1.5 2022/08/03 20:32:55 rillig Exp $

use strict;
use warnings;
use Test;

BEGIN { plan tests => 6, onfail => sub { die } }

require('../lintpkgsrc.pl');

ok(pkgversioncmp('3.4', '<', '3.4'), '');
ok(pkgversioncmp('3.4', '<=', '3.4'), 1);
ok(pkgversioncmp('3.4', '>=', '3.4.0.0.0'), 1);
ok(pkgversioncmp('3.4nb13', '>=', '3.4'), 1);
ok(pkgversioncmp('3.4nb13', '<', '3.4'), '');
ok(pkgversioncmp('3.4nb13', '>', '3.4nb5'), 1);
