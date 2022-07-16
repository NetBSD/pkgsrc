# $NetBSD: url2pkg.py,v 1.1 2022/07/16 08:59:38 rillig Exp $
#
# Forwards the module metadata from distutils and setuptools to url2pkg.

def print_depends(varname, depends):
    for dep in depends:
        print('%s\t%s%s' % (varname, dep.replace(' ', ''), '' if '>' in dep else '>=0'))


def print_var(varname, value):
    if value != '':
        print('var\t%s\t%s' % (varname, value))


def print_cmd(cmd, arg):
    print('\t'.join(('cmd', cmd, arg)))


def print_license(license_name):
    if license_name == '':
        return
    print_cmd('license', license_name)
    print_cmd(
        'license_default',
        '%s # TODO: from setup.py; needs to be adjusted' % license_name)


def setup(**kwargs):
    print_depends('DEPENDS', kwargs.get('requires', []))  # only for distutils.core
    print_depends('DEPENDS', kwargs.get('install_requires', []))
    print_depends('TEST_DEPENDS', kwargs.get('tests_require', []))
    print_depends('BUILD_DEPENDS', kwargs.get('extras_require', {}).get('dev', []))
    print_depends('BUILD_DEPENDS', kwargs.get('setup_requires', []))
    print_var('COMMENT', kwargs.get('description', '').rstrip('.'))
    print_var('HOMEPAGE', kwargs.get('url', ''))
    print_license(kwargs.get('license', ''))

    # TODO: implement 'python_requires'
    #  example pkgsrc package: devel/py-futures
    #  example values: >=2.6, <3, >=2.7, !=3.0.*, !=3.1.*, !=3.2.*, !=3.3.*
